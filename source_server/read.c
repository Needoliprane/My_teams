/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** read
*/

#include "server.h"

int handle_read_from_stdin()
{
    char read_buffer[DATA_MAXSIZE] = {0};
    message_t new_message = {0};

    if (read_from_stdin(read_buffer, DATA_MAXSIZE) != 0)
        return -1;
    prepare_message("Server", read_buffer, &new_message);
    print_message(&new_message);
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (connection_list[i].socket != NO_SOCKET) {
            if (peer_add_to_send(&connection_list[i], &new_message) != 0)
                continue;
        }
    }
    return 0;
}

int send_fast(char *data)
{
    message_t new_message = {0};

    prepare_message("Server", data, &new_message);
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (connection_list[i].socket != NO_SOCKET) {
            if (peer_add_to_send(&connection_list[i], &new_message) != 0) {
                printf("Send buffer was overflowed, we lost this message!\n");
                continue;
            }
            printf("New message to send was enqueued right now.\n");
        }
    }
    return (0);
}