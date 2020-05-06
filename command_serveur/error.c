/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** error
*/

#include "peer.h"
#include "server.h"

int error(peer_t *peer, char **data)
{
    printf("Error");
    send_fast("Error");
    return 0;
}