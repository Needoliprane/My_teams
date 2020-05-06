/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** delete_peer
*/

#include "peer.h"

int delete_peer(peer_t *peer)
{
    close(peer->socket);
    delete_message_queue(&peer->send_buffer);
    return (0);
}