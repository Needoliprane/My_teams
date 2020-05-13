/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** recive
*/

#include "client.h"
#include "peer.h"

int handle_received_message(message_t *message, peer_t *peer)
{
    printf("Received message from server.\n");
    if (strlen(message->data) > strlen("ok !"))
        print_message(message);
    return 0;
}