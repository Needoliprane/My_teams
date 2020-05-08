/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** use
*/

#include "peer.h"
#include "server.h"

int use(peer_t *peer, char **data)
{
    peer->use = true;
    send_fast("Ok !");
    return 0;
}