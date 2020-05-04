/*
** EPITECH PROJECT, 2020
** 4634731-6917058a9f6437092531794fa022aed8069e4aea
** File description:
** peer
*/

#ifndef PEER_H_
#define PEER_H_

#define MAX_SEND_SIZE 100

#define MAX_MESSAGES_BUFFER_SIZE 10

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>


#include "queue.h"
#include "message.h"

typedef struct {
    int socket;
    struct sockaddr_in addres;
    message_queue_t send_buffer;
    message_t sending_buffer;
    size_t current_sending_byte;
    message_t receiving_buffer;
    size_t current_receiving_byte;
    char *username;
} peer_t;

int read_from_stdin(char *read_buffer, size_t max_len);
int delete_peer(peer_t *peer);
int create_peer(peer_t *peer);
char *peer_get_addres_str(peer_t *peer);
int peer_add_to_send(peer_t *peer, message_t *message);
int receive_from_peer(peer_t *peer, int (*message_handler)(message_t *, peer_t *));
int send_to_peer(peer_t *peer);

#endif /* !PEER_H_ */
