/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** shell
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "client.h"

int call_command(char const **tab, int (* const command_action[])(client_user_t *, char *, int), client_user_t *data, char *command)
{
    int control = 0;

    for (int i = 0; tab[i]; i++) {
        if (strncmp(command, tab[i], strlen(tab[i])) == 0) {
            control = command_action[i](data, command, 0);
            break;
        }
    }
    return (control);
}

static int accept_new_client(int sock, int *client_socket)
{
    int csock;
    int done = 0;
    sockaddr_in_t new_connection = {0};
    unsigned int len = sizeof(new_connection);

    if ((csock = accept(sock, (struct sockaddr *)&new_connection, &len)) == -1) {
        exit(84);
    }
    for (int i = 0; done == 0 && i < 30; i++) {
        if (done == 0 && client_socket[i] == 0) {
            client_socket[i] = csock;
            done = 1;
        }
    }
    return (0);
}

static int init_select_tools(fd_set *readfs, int sock)
{
    FD_ZERO(readfs);
    FD_SET(sock, readfs);
    return (0);
}

static int doing_job(int csock)
{
    char *temporary;

    while (1) {
        if ((temporary = get_next_line(csock)) != NULL) {
            // read_client_command(csock, temporary);
        } else {
            return (84);
        }
    }
    if (temporary)
        free(temporary);
    if (close(csock) == -1)
        return (84);
    return (0);
}

int interprete_serveur_command(int *client_socket, fd_set readfs)
{
    int control = 0;

    for (int i = 0; i < 30; i++) {
        if (FD_ISSET(client_socket[i], &readfs)) {
            control = doing_job(client_socket[i]);
            client_socket[i] = 0;
        }
        if (control != 0) {
            return (84);
        }
    }
    return (0);
}

static void init_max_socket(int *sd, int *client_socket, int *max_sock, fd_set *readfs)
{
    int i = 0;

    for (i = 0; i < 30; ++i) {
        *sd = client_socket[i];
        (*sd > 0) ? (FD_SET(*sd, readfs)) : (*sd);
        (*sd > *max_sock) ? (*max_sock = *sd) : (*sd);
    }
}

int shell(char const **tab, int (* const command_action[])(client_user_t *, char *, int), client_user_t *data)
{
    char *command = NULL;
    fd_set readfs = {0};
    int client_socket[30] = {0};

    for (int max_sock = 0, sd = 0; 1;) {
        if ((command = get_next_line(0)) == NULL)
            continue;
        if (strcmp(command, "/quit") == 0)
            break;
        call_command(tab, command_action, data, command);
        free(command);
        max_sock = init_select_tools(&readfs, data->socket);
        init_max_socket(&sd, client_socket, &max_sock, &readfs);
        if (select(max_sock + 1, &readfs, NULL, NULL, NULL) == -1) {
            exit (84);
        }
        if (FD_ISSET(data->socket, &readfs)) {
            accept_new_client(data->socket, client_socket);
        }
        interprete_serveur_command(client_socket, readfs);
    }
    return (0);
}