/*
** EPITECH PROJECT, 2020
** 4634731-6917058a9f6437092531794fa022aed8069e4aea
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <unistd.h>
#include "peer.h"

#define MAX_CLIENTS 30
#define NO_SOCKET -1
#define SERVER_NAME "server"

extern peer_t connection_list[MAX_CLIENTS];
extern int listen_sock;

int handle_read_from_stdin();
int handle_received_message(message_t *message, peer_t *peer);
int handle_new_connection();
int close_client_connection(peer_t *client);
int master();
char **my_str_to_word_array_script(char const *str);
char *my_strcat(char *buf, char *tmp);
int send_fast(char *data);

/* Command */
int help(peer_t *peer, char **data);
int login(peer_t *peer, char **data);
int users(peer_t *peer, char **data);
int send_command(peer_t *peer, char **data);

#endif /* !SERVER_H_ */
