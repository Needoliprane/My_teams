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
    printf("here\n");
    if (data && data[1] != NULL) {
        peer->username = strdup(data[1]);
        send_fast("ok !");
        return 0;
    }
    return 84;
}