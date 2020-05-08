/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** messages
*/

#include "peer.h"
#include "server.h"

int messages(peer_t *peer, char **data)
{
    char *tmp = "";

    if (peer->username == NULL) {
        return (84);
    }
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if (connection_list[i].username != NULL && strcmp(connection_list[i].username, data[1]) == 0) {
            tmp = my_strcat(connection_list[i].message, tmp);
            tmp = my_strcat(tmp, " ; ");
        }
    }
    send_fast(my_strcat("ok ! ", tmp));
    return (0);
}