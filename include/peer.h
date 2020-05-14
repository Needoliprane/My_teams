/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
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
#include <unistd.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdbool.h>

#include "queue.h"
#include "message.h"

#define CHECK_GET_BYTE (peer->current_receiving_byte >= sizeof(peer->receiving_buffer))
#define BUF_RECV (char *)&peer->receiving_buffer + peer->current_receiving_byte
#define ERNO_CHECK_RECV (errno != EAGAIN || errno != EWOULDBLOCK)
#define ERNO_CHECK_RECV2 (errno == EAGAIN || errno == EWOULDBLOCK)
#define ERNO_SEND (errno == EAGAIN || errno == EWOULDBLOCK)
#define ERNO_SEND_CT (errno != EAGAIN || errno != EWOULDBLOCK)
#define SEND_BUFFER (char *)&peer->sending_buffer + peer->current_sending_byte

typedef struct {
    int socket;
    struct sockaddr_in addres;
    message_queue_t send_buffer;
    message_t sending_buffer;
    size_t current_sending_byte;
    message_t receiving_buffer;
    size_t current_receiving_byte;
    char *username;
    char *message;
    char *team;
    char *channel;
    char *channel_description;
    char *thread;
    char *uuid_user;
    char *uuid_team;
    char *uuid_channel;
    char *uuid_thread;
    char *list_user;
    char *team_description;
    bool use;
} peer_t;

int read_from_stdin(char *read_buffer, size_t max_len);
int delete_peer(peer_t *peer);
int create_peer(peer_t *peer);
char *peer_get_addres_str(peer_t *peer);
int peer_add_to_send(peer_t *peer, message_t *message);
int receive_from_peer(peer_t *peer, int (*message_handler)(message_t *, peer_t *));
int send_to_peer(peer_t *peer);

#endif /* !PEER_H_ */
