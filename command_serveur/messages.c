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
    int control = 84;

    if (peer->username == NULL) {
        return (84);
    }
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if (connection_list[i].username != NULL && strcmp(connection_list[i].username, data[1]) == 0) {
            if (data[2]) {
                tmp = my_strcat(connection_list[i].message, data[2]);
                tmp = my_strcat(tmp, " ; ");
                server_event_private_message_sended(peer->uuid_user, data[1], data[2]);
                control = 0;
            }
        }
    }
    send_fast(my_strcat("ok ! \"", my_strcat(tmp, "\"")));
    return (control);
}