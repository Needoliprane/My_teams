/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** peer_add_to_send
*/

#include "peer.h"

int peer_add_to_send(peer_t *peer, message_t *message)
{
    return (enqueue(&peer->send_buffer, message));
}