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
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (connection_list[i].username != NULL && connection_list[i].uuid_user != NULL) {
            printf("username => %s\n", connection_list[i].username);
            tmp = my_strcat(connection_list[i].username, tmp);
            tmp = my_strcat(tmp, " ; ");
            tmp = my_strcat(tmp, connection_list[i].uuid_user);
            tmp = my_strcat(tmp, " ; ");
        }
    }
    send_fast(my_strcat("ok ! ", tmp));
    return (0);
}