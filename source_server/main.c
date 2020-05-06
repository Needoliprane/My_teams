/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main
*/

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "sig_handle.h"
#include "server.h"

static int print_help(int ret)
{
    printf("USAGE:\t./myteams_cli ip port\n");
    printf("\tip\tis the server ip address on which the server socket");
    printf("listens\n");
    printf("\tport\tis the port number on which the server socket listens\n");
    return (ret);
}

int dont_fuck_with_me(char *av)
{
    for (int i = 0; i< av[i]; i++) {
        if (!isdigit(av[i])) {
            return (84);
        }
    }
    return (0);
}

int start_listen_socket(int *listen_sock, int port)
{
    struct sockaddr_in my_addr = {0};
    int reuse = 1;

    *listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (*listen_sock < 0)
        return -1;
    if (setsockopt(*listen_sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) != 0)
        return -1;
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    my_addr.sin_port = htons(port);
    if (bind(*listen_sock, (struct sockaddr*)&my_addr, sizeof(struct sockaddr)) != 0)
        return -1;
    if (listen(*listen_sock, 10) != 0)
        return -1;
    printf("Accepting connections on port %d.\n", (int)port);
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "help") == 0) {
        return (print_help(0));
    }
    else if (ac == 2 && dont_fuck_with_me(av[1]) == 0) {
        if (setup_signals() != 0)
            exit(EXIT_FAILURE);
        if (start_listen_socket(&listen_sock, atoi(av[1])) != 0)
            exit(EXIT_FAILURE);
        return (master());
    }
    return (print_help(84));
}