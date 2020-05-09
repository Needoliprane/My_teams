/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** recive
*/

#include "peer.h"
#include "server.h"

char const *tabu[] = {"help","login", "users", "user", "send", "messages", "subscribe","subscribed","unsubscribe" ,"use" ,"create" ,"list","info", NULL};
int (* const command[])(peer_t *, char **data) = {help, login, users, user, send_command, help, help, help, help, use, create, help, help, NULL};

int handle_received_message(message_t *message, peer_t *peer)
{
    char **data = NULL;
    int control = 84;

    printf("Received message from server.\n");
    printf("%s\n", message->data);
    data = my_str_to_word_array_script(message->data);
    if (data == NULL) {
        return(send_fast("Error"));
    }
    for (int i =0; data[i]; i++) {
        printf("%s\n", data[i]);
    }
    for (int i = 0; tabu[i]; i++) {
        printf("%s - %s\n", data[0], tabu[i]);
        if (strncmp(data[0], tabu[i], strlen(tabu[i])) == 0) {
            control = command[i](peer, data);
            break;
        }
    }
    if (control == 84)
        error(peer, data);
    return 0;
}