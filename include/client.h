/*
** EPITECH PROJECT, 2020
** 4634731-6917058a9f6437092531794fa022aed8069e4aea
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
#include "signal_client.h"

int handle_received_message(message_t *message, peer_t *peer);
int handle_read_from_stdin(peer_t *server, char *client_name);
int validate_ip(char *ip);
int master(char **av);
int build_fd_sets(peer_t *server, fd_set *read_fds, fd_set *write_fds, fd_set *except_fds);
char **my_str_to_word_array_script(char const *str);

extern peer_t server;

#endif /* !CLIENT_H_ */
