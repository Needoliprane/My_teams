/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** recive
*/

#include "client.h"
#include "peer.h"

int doing_the_job(message_t *message)
{
    if (command.last_command == NULL)
        return (0);
    if (strncmp(command.last_command, "/users", strlen("/users")) == 0)
        print_users(message->data);
    return (0);
}

int check_message_error(message_t *message)
{
    if (strncmp(message->data,"ok !", strlen("Ok !")) == 0) {
        if (strlen(message->data) > strlen("Ok !")) {
            doing_the_job(message);
        }
    }
    if (strncmp(message->data, "Error", strlen("Error")) == 0) {
        client_error_unauthorized();
    }
    return (0);
}

int handle_received_message(message_t *message, peer_t *peer)
{
    printf("Received message from server.\n");
    printf("%s\n", command.last_command);
    print_message(message);
    check_message_error(message);
    return 0;
}