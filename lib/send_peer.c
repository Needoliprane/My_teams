/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send_peer
*/

#include <unistd.h>
#include "peer.h"

static int for_the_norm(peer_t *peer)
{
    if (dequeue(&peer->send_buffer, &peer->sending_buffer) != 0) {
        peer->current_sending_byte = -1;
        return (0);
    }
    return (1);
}

int send_to_peer(peer_t *peer)
{
    size_t len_to_send;
    ssize_t send_count;
    size_t send_total = 0;

    do {
        if (peer->current_sending_byte >= sizeof(peer->sending_buffer)) {
            if (for_the_norm(peer) == 0)
                break;
            peer->current_sending_byte = 0;
        }
        len_to_send = sizeof(peer->sending_buffer) - peer->current_sending_byte;
        (len_to_send > MAX_SEND_SIZE) ? len_to_send = MAX_SEND_SIZE : 0;
        send_count = send(peer->socket, SEND_BUFFER, len_to_send, 0);
        if (send_count < 0 && ERNO_SEND_CT)
                return -1;
        else if (send_count == 0 || (send_count < 0 && ERNO_SEND))
            break;
        (send_count > 0) ? peer->current_sending_byte += send_count : 0;
        (send_count > 0) ? send_total += send_count : 0;
    } while (send_count > 0);
    return 0;
}