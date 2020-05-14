/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** login
*/

/*
** EPITECH PROJECT, 2020
** 4634731-6917058a9f6437092531794fa022aed8069e4aea
** File description:
** recive
*/

#include "peer.h"
#include "server.h"

int login(peer_t *peer, char **data)
{
    if (data && data[1] != NULL) {
        peer->username = strdup(data[1]);
        send_fast("ok !");
        server_event_user_logged_in(peer->username);
        return 0;
    }
    return 84;
}

int logout(peer_t *peer, char **data)
{
    if (data && data[1] != NULL) {
        peer->username = strdup(data[1]);
        send_fast("ok !");
        server_event_user_logged_out(peer->username);
        return 0;
    }
    return 84;
}