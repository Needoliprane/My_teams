/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/

#include "sig_handle.h"
#include "peer.h"
#include "client.h"

peer_t server = {0};

static int for_the_norm(int value, char **av, fd_set *read_fds, fd_set *write_fds, fd_set *except_fds)
{
    if (value <= 0)
        shutdown_properly(EXIT_FAILURE);
    if (FD_ISSET(STDIN_FILENO, read_fds))
        if (handle_read_from_stdin(&server, av[1]) != 0)
            shutdown_properly(EXIT_FAILURE);
    if (FD_ISSET(STDIN_FILENO, except_fds) || FD_ISSET(server.socket, except_fds)) {
        shutdown_properly(EXIT_FAILURE);
    }
    if (FD_ISSET(server.socket, read_fds))
        if (receive_from_peer(&server, &handle_received_message) != 0)
            shutdown_properly(EXIT_FAILURE);
    if (FD_ISSET(server.socket, write_fds)) {
        if (send_to_peer(&server) != 0)
            shutdown_properly(EXIT_FAILURE);
    }
    return (0);
}

int master(char **av)
{
    int value = 0;

    for (fd_set read_fds, write_fds, except_fds;1;) {
        build_fd_sets(&server, &read_fds, &write_fds, &except_fds);
        value = select(server.socket + 1, &read_fds, &write_fds, &except_fds, NULL);
        for_the_norm(value, av, &read_fds, &write_fds, &except_fds);
        printf("waiting for server or stdin activity. Something to send:\n");
    }
    return 0;
}
