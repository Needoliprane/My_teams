/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#include "peer.h"
#include "signal.h"

#include "../libs/myteams/logging_client.h"

typedef struct client_command_s {
    char *username;
    char *uuid_user;
    char *team_name;
    char *channel_name;
    char *thread_name;
    char *last_command;
} client_command_t;

extern client_command_t command;

#define SERV_D (struct sockaddr *)&server_addr
#define SIZE_SERV_DATA sizeof(struct sockaddr)
#define SET_SOCKET server->send_buffer.current > 0
#define CHECK_BORING_CASE strncmp(str, "/create", strlen("/create")) \
    == -1 && strncmp(str, "/list", strlen("/list")) == -1 && strncmp(str, \
    "/info", strlen("/info")) == -1

int handle_received_message(message_t *message, peer_t *peer);
int handle_read_from_stdin(peer_t *server, char *client_name);
int validate_ip(char *ip);
int master(char **av);
int build_fd_sets(peer_t *server, fd_set *read_fds, fd_set *write_fds, fd_set *except_fds);
char **my_str_to_word_array_script(char const *str);
char *my_strcat(char *buf, char *tmp);
char *build_uuid();
char **my_str_to_word_array(char const *str);

extern peer_t server;

int print_users(char *answer);
int print_teams(char *answer);

#endif /* !CLIENT_H_ */
