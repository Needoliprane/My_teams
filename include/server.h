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
int handle_received_message(message_t *message);
int handle_new_connection();
int close_client_connection(peer_t *client);
int master();

#endif /* !SERVER_H_ */
