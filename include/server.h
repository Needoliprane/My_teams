/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
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
#include "../libs/myteams/logging_server.h"

#define MAX_CLIENTS 30
#define NO_SOCKET -1
#define CLIENT_ADD (struct sockaddr *)&client_addr
#define CHECK_SOCKET connection_list[i].socket != NO_SOCKET
#define CHECK_ISSET_READ FD_ISSET(connection_list[i].socket, read_fds)
#define CALL_RECEIVE receive_from_peer(&connection_list[i], &handle_received_message) != 0
#define CHECK_ISSET_WRITE FD_ISSET(connection_list[i].socket, write_fds)
#define CALL_SEND send_to_peer(&connection_list[i]) != 0
#define CHECK_SIZE (strlen(data[index]) < 2)

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
int error(peer_t *peer, char **data);
int login(peer_t *peer, char **data);
int users(peer_t *peer, char **data);
int send_command(peer_t *peer, char **data);
int user(peer_t *peer, char **data);
int create(peer_t *peer, char **data);
int use(peer_t *peer, char **data);
int list(peer_t *peer, char **data);

#endif /* !SERVER_H_ */
