/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <stdbool.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/stat.h>
#include <string.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdlib.h>

typedef struct sockaddr_in sockaddr_in_t;

typedef struct client_user_s {
    char *user;
    int socket;
} client_user_t;

int master(char **info);
int shell(char const **tab, int (* const command_action[])(client_user_t *, char *, int), client_user_t *data);

// Lib
char **my_str_to_word_array_script(char const *str);
char *get_next_line(int fd);
void free_tab(void **tab);

// Command
int help(client_user_t *user, char *check, int sock);
int login(client_user_t *user, char *check, int sock);
int logout(client_user_t *user, char *check, int sock);

#endif /* !CLIENT_H_ */
