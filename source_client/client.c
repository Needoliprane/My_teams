/*
** EPITECH PROJECT, 2020
** 4634731-6917058a9f6437092531794fa022aed8069e4aea
** File description:
** client
*/

#include "signal_client.h"
#include "peer.h"
#include "client.h"
 
peer_t server = {0};

int master(char **av)
{
    fd_set read_fds;
    fd_set write_fds;
    fd_set except_fds;
    printf("Waiting for server message or stdin input. Please, type text to send:\n");

    int maxfd = server.socket;
    while (1) {
        build_fd_sets(&server, &read_fds, &write_fds, &except_fds);
        switch (select(maxfd + 1, &read_fds, &write_fds, &except_fds, NULL)) {
            case -1:
                shutdown_properly(EXIT_FAILURE);
                break;
            case 0:
                shutdown_properly(EXIT_FAILURE);
                break;
            default:
                if (FD_ISSET(STDIN_FILENO, &read_fds)) {
                    if (handle_read_from_stdin(&server, av[1]) != 0)
                        shutdown_properly(EXIT_FAILURE);
                }
                if (FD_ISSET(STDIN_FILENO, &except_fds)) {
                    shutdown_properly(EXIT_FAILURE);
                }
                if (FD_ISSET(server.socket, &read_fds)) {
                    if (receive_from_peer(&server, &handle_received_message) != 0)
                        shutdown_properly(EXIT_FAILURE);
                }
                if (FD_ISSET(server.socket, &write_fds)) {
                    if (send_to_peer(&server) != 0)
                        shutdown_properly(EXIT_FAILURE);
                }
                if (FD_ISSET(server.socket, &except_fds)) {
                    printf("except_fds for server.\n");
                    shutdown_properly(EXIT_FAILURE);
                }
                break;
        }
        printf("And we are still waiting for server or stdin activity. You can type something to send:\n");
    }
    return 0;
}
