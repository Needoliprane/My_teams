/*
** EPITECH PROJECT, 2020
** 4634731-6917058a9f6437092531794fa022aed8069e4aea
** File description:
** recive
*/

#include "peer.h"
#include "server.h"

char const *tab[] = {"help","login", "users", "user", "send","messages","subscribe","subscribed","unsubscribe" ,"use" ,"create" ,"list","info", NULL};
int (* const command[])(peer_t *, char **data) = {help, login, users, help, send_command, help, help, help, help, help, help, help, help, NULL};

int help(peer_t *peer, char **data)
{
    send_fast("ok !");
    return 0;
}

int login(peer_t *peer, char **data)
{
    printf("here\n");
    if (data && data[1] != NULL) {
        peer->username = strdup(data[1]);
        send_fast("ok !");
        return 0;
    }
    return 84;
}

int error(peer_t *peer, char **data)
{
    printf("Error");
    send_fast("Error");
    return 0;
}

int users(peer_t *peer, char **data)
{
    char *tmp = "";

    if (peer->username == NULL) {
        return (84);
    }
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if (connection_list[i].username != NULL) {
            tmp = my_strcat(connection_list[i].username, tmp);
            tmp = my_strcat(tmp, " ; ");
        }
    }
    send_fast(my_strcat("ok ! ", tmp));
    return (0);
}

int send_command(peer_t *peer, char **data)
{
    if (peer->username == NULL) {
        return (84);
    }
    send_fast(my_strcat(my_strcat("ok ! ; ", data[1]), my_strcat(" ; ", data[2])));
    return (0);
}

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
    for (int i = 0; tab[i]; i++) {
        printf("%s - %s\n", data[0], tab[i]);
        if (strncmp(data[0], tab[i], strlen(tab[i])) == 0) {
            control = command[i](peer, data);
            break;
        }
    }
    if (control == 84)
        error(peer, data);
    return 0;
}