/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_peer
*/

#include "peer.h"

int create_peer(peer_t *peer)
{
    create_message_queue(MAX_MESSAGES_BUFFER_SIZE, &peer->send_buffer);
    peer->current_sending_byte = -1;
    peer->current_receiving_byte = 0;
    return 0;
}