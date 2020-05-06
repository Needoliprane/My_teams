/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** get_add_peer
*/

#include <unistd.h>
#include "peer.h"

char *peer_get_addres_str(peer_t *peer)
{
    static char ret[INET_ADDRSTRLEN + 10];
    char peer_ipv4_str[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &peer->addres.sin_addr, peer_ipv4_str, INET_ADDRSTRLEN);
    sprintf(ret, "%s:%d", peer_ipv4_str, peer->addres.sin_port);
    return ret;
}