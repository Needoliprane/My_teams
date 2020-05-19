/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** login
*/

#include "peer.h"
#include "server.h"

int login(peer_t *peer, char **data)
{
    if (data && data[1] != NULL) {
        peer->username = strdup(data[1]);
        peer->uuid_user = build_uuid();
        send_fast("ok !");
        server_event_user_logged_in(peer->username);
        return 0;
    }
    return 84;
}

int logout(peer_t *peer, char **data)
{
    send_fast("ok !");
    server_event_user_logged_out(peer->username);
    free(peer->username);
    peer->username = NULL;
    return (0);
}