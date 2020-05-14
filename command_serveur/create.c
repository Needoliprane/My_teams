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
        server_event_team_created(data[1], data[1], peer->username);
        peer->team = strdup(data[1]);
        peer->uuid_team = build_uuid();
        peer->team_description = tmp;
    } else if (peer->channel == NULL) {
        server_event_channel_created(peer->team, data[1], peer->username);
        peer->channel = strdup(data[1]);
        peer->uuid_channel = build_uuid();
        peer->channel_description = tmp;
    } else if (peer->thread == NULL) {
        server_event_thread_created(peer->channel, data[1], peer->username, tmp);
        peer->thread = strdup(data[1]);
        peer->uuid_thread = build_uuid();
        peer->message = tmp;
    } else {
        peer->message = my_strcat(peer->message, my_strcat(" ; ", data[1]));
        server_event_thread_new_message(peer->thread, peer->username, data[1]);
    }
    send_fast("Ok !");
    return (0);
}