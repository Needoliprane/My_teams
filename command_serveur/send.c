/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send
*/

#include "peer.h"
#include "server.h"

int send_command(peer_t *peer, char **data)
{
    int index = 2;

    if (peer->username == NULL)
        return (84);
    if (data[index] == NULL)
        return (84);
    (CHECK_SIZE) ? index++ : 0;
    send_fast(my_strcat(my_strcat("ok ! ; ", data[1]), my_strcat(" ; ", data[index])));
    if (peer->message == NULL)
        peer->message = strdup(data[index]);
    else
        peer->message = my_strcat(peer->message, my_strcat(" ; ", data[index]));
    return (0);
}