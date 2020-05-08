/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** read
*/

#include "client.h"

int handle_read_from_stdin(peer_t *server, char *client_name)
{
    char read_buffer[DATA_MAXSIZE];
    message_t new_message;

    if (read_from_stdin(read_buffer, DATA_MAXSIZE) != 0)
        return -1;
    prepare_message(client_name, read_buffer, &new_message);
    print_message(&new_message);
    if (peer_add_to_send(server, &new_message) != 0) {
        return 0;
    }
    return 0;
}