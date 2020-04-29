/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** master
*/

#include "client.h"

int prep_sock(char **av)
{
    int sock = 0;
    sockaddr_in_t sock_addr_in = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        return (84);
    sock_addr_in.sin_family = AF_INET;
    sock_addr_in.sin_addr.s_addr = htonl(INADDR_ANY);
    sock_addr_in.sin_port = htons(atoi(av[1]));
    if (bind(sock, (struct sockaddr *)&sock_addr_in, sizeof(sock_addr_in))
                                                                    == -1)
        return (84);
    if (listen(sock, 30) == -1)
        return (84);
    return (sock);
}

int master(char **info)
{
    char const *tab[] = {"/help","/login", "/logout", "/users", "/user", "/send","/messages","/subscribe","/subscribed","/unsubscribe" ,"/use" ,"/create" ,"/list","/info", NULL};
    int (* const command[])(client_user_t *, char *, int) = {help, login, logout, help, help, help, help, help, help, help, help, help, help, help, NULL};
    client_user_t data;

    data.socket = prep_sock(info);
    shell(tab, command, &data);
    return (0);
}