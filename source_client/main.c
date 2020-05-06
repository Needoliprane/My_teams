/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main
*/

#include <ctype.h>
#include "client.h"
#include "sig_handle.h"

static int print_help(int ac)
{
    printf("USAGE:\t./myteams_cli ip port\n");
    printf("\tip\tis the server ip address on which the server socket");
    printf("listens\n");
    printf("\tport\tis the port number on which the server socket listens\n");
    if (ac == 2) {
        return (0);
    }
    return (84);
}

static int dont_fuck_with_me(char *av)
{
    for (int i = 0; i< av[i]; i++) {
        if (!isdigit(av[i])) {
            return (84);
        }
    }
    return (0);
}

static int connect_server(peer_t *server, char **av)
{
    struct sockaddr_in server_addr = {0};
    server->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server->socket < 0) {
        return -1;
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(av[1]);
    server_addr.sin_port = htons(atoi(av[2]));
    server->addres = server_addr;
    if (connect(server->socket, SERV_D, SIZE_SERV_DATA) != 0) {
        return -1;
    }
    printf("Connected to %s:%s.\n", av[1], av[2]);
    return 0;
}

int build_fd_sets(peer_t *server, fd_set *read_fds, fd_set *write_fds,
                                                    fd_set *except_fds)
{
    FD_ZERO(read_fds);
    FD_SET(STDIN_FILENO, read_fds);
    FD_SET(server->socket, read_fds);
    FD_ZERO(write_fds);
    (SET_SOCKET) ? FD_SET(server->socket, write_fds) : 0;
    FD_ZERO(except_fds);
    FD_SET(STDIN_FILENO, except_fds);
    FD_SET(server->socket, except_fds);
    return 0;
}

int main(int ac, char **av)
{
    int flag = fcntl(STDIN_FILENO, F_GETFL, 0);

    if (ac != 3) {
        return (print_help(ac));
    }
    if (validate_ip(strdup(av[1])) == 84 || dont_fuck_with_me(av[2]) == 84)
        return (print_help(0));
    if (setup_signals() != 0)
        exit(EXIT_FAILURE);
    create_peer(&server);
    if (connect_server(&server, av) != 0)
        shutdown_properly(EXIT_FAILURE);
    flag |= O_NONBLOCK;
    fcntl(STDIN_FILENO, F_SETFL, flag);
    return (master(av));
}