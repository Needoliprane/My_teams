/*
** EPITECH PROJECT, 2020
** 4634731-6917058a9f6437092531794fa022aed8069e4aea
** File description:
** handle_connection
*/

#include "server.h"

int handle_new_connection()
{
    struct sockaddr_in client_addr = {0};
    socklen_t client_len = sizeof(client_addr);
    int new_client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_len);
    char client_ipv4_str[INET_ADDRSTRLEN] = {0};

    if (new_client_sock < 0)
        return -1;
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ipv4_str, INET_ADDRSTRLEN);
    printf("Incoming connection from %s:%d.\n", client_ipv4_str, client_addr.sin_port);
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (connection_list[i].socket == NO_SOCKET) {
            connection_list[i].socket = new_client_sock;
            connection_list[i].addres = client_addr;
            connection_list[i].current_sending_byte   = -1;
            connection_list[i].current_receiving_byte = 0;
            return 0;
        }
    }
    printf("There is too much connections. Close new connection %s:%d.\n", client_ipv4_str, client_addr.sin_port);
    close(new_client_sock);
    return -1;
}

int close_client_connection(peer_t *client)
{
    printf("Close client socket for %s.\n", peer_get_addres_str(client));
    close(client->socket);
    client->socket = NO_SOCKET;
    dequeue_all(&client->send_buffer);
    client->current_sending_byte   = -1;
    client->current_receiving_byte = 0;
    return (0);
}