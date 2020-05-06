/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** users
*/

#include "peer.h"
#include "server.h"

int users(peer_t *peer, char **data)
{
    char *tmp = "";

    if (peer->username == NULL) {
        return (84);
    }
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if (connection_list[i].username != NULL) {
            tmp = my_strcat(connection_list[i].username, tmp);
            tmp = my_strcat(tmp, " ; ");
        }
    }
    send_fast(my_strcat("ok ! ", tmp));
    return (0);
}