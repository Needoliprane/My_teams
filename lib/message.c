/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message
*/

#include "message.h"

char const *tab[] = {"/help", "/login", "/logout", \
    "/users", "/user", "/send", "/messages", "/subscribe", \
    "/subscribed", "/unsubscribe", "/use", "/create", "/list", "/info", NULL};

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

int validate_message_client(message_t *message)
{
    if (message->data == NULL) {
        return (84);
    }
    printf("validate %s\n", message->data);
    if (message->data[0] != '/')
        return (84);
    printf("here\n");
    for (int i = 0; tab[i]; i++) {
        if (strncmp(message->data, tab[i], strlen(tab[i])) == 0) {
            return (0);
        }
    }
    return (84);
}