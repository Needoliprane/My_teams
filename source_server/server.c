/*
** EPITECH PROJECT, 2020
** 4634731-6917058a9f6437092531794fa022aed8069e4aea
** File description:
** server
*/

#include "signal_server.h"
#include "server.h"

int listen_sock = 0;
peer_t connection_list[MAX_CLIENTS] = {0};
char read_buffer[1024];

int build_fd_sets(fd_set *read_fds, fd_set *write_fds, fd_set *except_fds)
{
    int i;

    FD_ZERO(read_fds);
    FD_SET(STDIN_FILENO, read_fds);
    FD_SET(listen_sock, read_fds);
    for (i = 0; i < MAX_CLIENTS; ++i)
        if (connection_list[i].socket != NO_SOCKET)
            FD_SET(connection_list[i].socket, read_fds);
    FD_ZERO(write_fds);
    for (i = 0; i < MAX_CLIENTS; ++i)
        if (connection_list[i].socket != NO_SOCKET && connection_list[i].send_buffer.current > 0)
            FD_SET(connection_list[i].socket, write_fds);
    FD_ZERO(except_fds);
    FD_SET(STDIN_FILENO, except_fds);
    FD_SET(listen_sock, except_fds);
    for (i = 0; i < MAX_CLIENTS; ++i)
        if (connection_list[i].socket != NO_SOCKET)
            FD_SET(connection_list[i].socket, except_fds);
    return 0;
}

void prep()
{
    int flag = fcntl(STDIN_FILENO, F_GETFL, 0);
    int i;

    flag |= O_NONBLOCK;
    fcntl(STDIN_FILENO, F_SETFL, flag);
    for (i = 0; i < MAX_CLIENTS; ++i) {
        connection_list[i].socket = NO_SOCKET;
        create_peer(&connection_list[i]);
    }
}

int master()
{
    int high_sock = listen_sock;

    prep();
    printf("Waiting for incoming connections.\n");
    for (fd_set read_fds, write_fds, except_fds; 1 ;) {
        build_fd_sets(&read_fds, &write_fds, &except_fds);
        high_sock = listen_sock;
        for (int i = 0; i < MAX_CLIENTS; ++i) {
            if (connection_list[i].socket > high_sock)
                high_sock = connection_list[i].socket;
        }
        switch (select(high_sock + 1, &read_fds, &write_fds, &except_fds, NULL)) {
            case -1:
                shutdown_properly(EXIT_FAILURE);
                break;
            case 0:
                shutdown_properly(EXIT_FAILURE);
                break;
            default:
                if (FD_ISSET(STDIN_FILENO, &read_fds)) {
                    if (handle_read_from_stdin() != 0)
                        shutdown_properly(EXIT_FAILURE);
                }
                if (FD_ISSET(listen_sock, &read_fds)) {
                    handle_new_connection();
                }
                if (FD_ISSET(STDIN_FILENO, &except_fds)) {
                    shutdown_properly(EXIT_FAILURE);
                }
                if (FD_ISSET(listen_sock, &except_fds)) {
                    shutdown_properly(EXIT_FAILURE);
                }
                for (int i = 0; i < MAX_CLIENTS; ++i) {
                    if (connection_list[i].socket != NO_SOCKET && FD_ISSET(connection_list[i].socket, &read_fds)) {
                        if (receive_from_peer(&connection_list[i], &handle_received_message) != 0) {
                            close_client_connection(&connection_list[i]);
                            continue;
                        }
                    }
                    if (connection_list[i].socket != NO_SOCKET && FD_ISSET(connection_list[i].socket, &write_fds)) {
                        if (send_to_peer(&connection_list[i]) != 0) {
                            close_client_connection(&connection_list[i]);
                            continue;
                        }
                    }
                    if (connection_list[i].socket != NO_SOCKET && FD_ISSET(connection_list[i].socket, &except_fds)) {
                        close_client_connection(&connection_list[i]);
                        continue;
                    }
                }
                break;
            }
        printf("And we are still waiting for clients' or stdin activity. You can type something to send:\n");
    }
    return 0;
}
