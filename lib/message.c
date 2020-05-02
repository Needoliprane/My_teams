/*
** EPITECH PROJECT, 2020
** 4634731-6917058a9f6437092531794fa022aed8069e4aea
** File description:
** message
*/

#include "message.h"

int prepare_message(char *sender, char *data, message_t *message)
{
    sprintf(message->sender, "%s", sender);
    sprintf(message->data, "%s", data);
    return 0;
}
 
int print_message(message_t *message)
{
    printf("Message: \"%s: %s\"\n", message->sender, message->data);
    return 0;
}