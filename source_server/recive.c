/*
** EPITECH PROJECT, 2020
** 4634731-6917058a9f6437092531794fa022aed8069e4aea
** File description:
** recive
*/

#include "peer.h"

int handle_received_message(message_t *message)
{
    printf("Received message from server.\n");
    print_message(message);
    return 0;
}