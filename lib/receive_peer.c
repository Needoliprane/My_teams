/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** receive_peer
*/

#include <unistd.h>
#include "peer.h"

int receive_from_peer(peer_t *peer, int(*message_handler)(message_t*, peer_t*))
{
    size_t len;
    ssize_t count_get;
    size_t tot_get = 0;

    do {
        (CHECK_GET_BYTE) ? message_handler(&peer->receiving_buffer, peer) : 0;
        (CHECK_GET_BYTE) ? peer->current_receiving_byte = 0 : 0;
        len = sizeof(peer->receiving_buffer) - peer->current_receiving_byte;
        (len > MAX_SEND_SIZE) ? len = MAX_SEND_SIZE : 0;
        count_get = recv(peer->socket, BUF_RECV, len, MSG_DONTWAIT);
        if (count_get < 0 && (ERNO_CHECK_RECV))
            return -1;
        else if (count_get < 0 && (ERNO_CHECK_RECV2))
            break;
        else if (count_get == 0)
            return -1;
        (count_get > 0) ? peer->current_receiving_byte += count_get : 0;
        (count_get > 0) ? tot_get += count_get : 0;
    } while (count_get > 0);
    return 0;
}