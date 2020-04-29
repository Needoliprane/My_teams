/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main
*/

#include <string.h>
#include <stdio.h>

static int print_help(int ret)
{
    printf("USAGE:\t./myteams_cli ip port\n");
    printf("\tip\tis the server ip address on which the server socket");
    printf("listens\n");
    printf("\tport\tis the port number on which the server socket listens\n");
    return (ret);
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "help") == 0) {
        return (print_help(0));
    }
    else if (ac == 2) {
        return (0);
    }
    return (print_help(84));
}