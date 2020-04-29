/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main
*/

#include <stdio.h>
#include "client.h"

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

int main(int ac, char **av)
{
    if (ac != 3) {
        return (print_help(ac));
    }
    return (master(av + 1));
}