/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create
*/

#include "peer.h"
#include "server.h"

int create(peer_t *peer, char **data)
{
    int index = 2;
    char *tmp = strdup((CHECK_SIZE) ? data[index++] : data[index]);

    if (peer->username == NULL) {
        return (84);
    } else if (peer->team == NULL) {
        peer->team = strdup(data[1]);
        peer->team_description = tmp;
    } else if (peer->channel == NULL) {
        peer->channel = strdup(data[1]);
        peer->channel_description = tmp;
    } else if (peer->thread == NULL) {
        peer->thread = strdup(data[1]);
        peer->message = tmp;
    } else {
        peer->message = my_strcat(peer->message, my_strcat(" ; ", peer->message));
    }
    send_fast("Ok !");
    return (0);
}