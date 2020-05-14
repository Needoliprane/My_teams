/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list
*/

#include "peer.h"
#include "server.h"

static int list_teams(peer_t *pper, char **data);
static int list_channel(peer_t *pper, char **data);
static int list_thread(peer_t *pper, char **data);
static int list_replies(peer_t *pper, char **data);

int list(peer_t *peer, char **data)
{
    if (peer->username == NULL) {
        return (84);
    }
    if (peer->use == false) {
        return (list_teams(peer, data));
    }
    list_thread(peer, data);
    list_replies(peer, data);
    list_channel(peer, data);
    return (0);
}

static int list_teams(peer_t *pper, char **data)
{
    char *tmp = "";

    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (connection_list[i].team != NULL) {
            tmp = my_strcat(connection_list[i].team, tmp);
            tmp = my_strcat(tmp, " ; ");
        }
    }
    send_fast(my_strcat("Ok ! ", tmp));
    return (0);
}

static int list_channel(peer_t *pper, char **data)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (strcmp(connection_list[i].team, data[1]) == 0) {
            send_fast(my_strcat("Ok ! ", connection_list[i].channel));
            return (0);
        }
    }
    return (84);
}

static int list_thread(peer_t *pper, char **data)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (strcmp(connection_list[i].channel, data[1]) == 0) {
            send_fast(my_strcat("Ok ! ", connection_list[i].thread));
            return (0);
        }
    }
    return (84);
}

static int list_replies(peer_t *pper, char **data)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (strcmp(connection_list[i].channel, data[1]) == 0) {
            send_fast(my_strcat("Ok ! ", connection_list[i].message));
            return (0);
        }
    }
    return (84);
}