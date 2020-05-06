/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send
*/

#include "peer.h"
#include "server.h"

int send_command(peer_t *peer, char **data)
{
    if (peer->username == NULL) {
        return (84);
    }
    send_fast(my_strcat(my_strcat("ok ! ; ", data[1]), my_strcat(" ; ", data[2])));
    return (0);
}