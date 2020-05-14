/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** read
*/

#include "sig_handle.h"
#include "client.h"

int is_logout(message_t *message)
{
    if (strncmp(message->data, "/logout", strlen("/logout")) == 0) {
        exit(0);
    }
    return (0);
}

int update_client(char *str)
{
    char **data;

    if (command.last_command != NULL)
        free(command.last_command);
    command.last_command = strdup(str);
    data = my_str_to_word_array_script(str);
    if (strncmp(str, "/login", strlen("/login")) == 0) {
        (command.username == NULL) ? command.username = strdup(data[1]) : 0;
        return (0);
    }
    if (strncmp(str, "/user", strlen("/user")) == 0)
        return (0);
    if (strncmp(str, "/users", strlen("/users")) == 0)
        return (0);
    if (strncmp(str, "/send", strlen("/send")) == 0)
        return (0);
    if (command.team_name == NULL)
        command.team_name = strdup(data[1]);
    else if (command.channel_name == NULL)
        command.channel_name = strdup(data[1]);
    else if (command.thread_name == NULL)
        command.thread_name = strdup(data[1]);
    return (1);
}

char *dump_command(void)
{
    char *tmp = "";

    if (command.team_name != NULL)
        tmp = my_strcat(tmp, command.team_name);
    else if (command.channel_name != NULL)
        tmp = my_strcat(my_strcat(tmp, " ; "), command.channel_name);
    else if (command.thread_name != NULL)
        tmp = my_strcat(my_strcat(tmp, " ; "), command.thread_name);
    return (my_strcat(" ; ", tmp));
}

int handle_read_from_stdin(peer_t *server, char *client_name)
{
    char read_buffer[DATA_MAXSIZE] = {0};
    char *msg = NULL;
    message_t nw_msg;

    if (read_from_stdin(read_buffer, DATA_MAXSIZE) != 0)
        return -1;
    prepare_message(client_name, read_buffer, &nw_msg);
    if (validate_message_client(&nw_msg) == 84) {
        printf("Error invalid syntax or invalid command\n");
        return (0);
    }
    is_logout(&nw_msg);
    if (update_client(nw_msg.data) == 1) {
        msg = my_strcat(nw_msg.data, dump_command());
        printf("VIP : %s\n", msg);
    } else {
        msg = strdup(nw_msg.data);
        printf("Non VIP : %s\n", msg);
    }
    strcpy(nw_msg.data, msg);
    print_message(&nw_msg);
    if (peer_add_to_send(server, &nw_msg) != 0) {
        return 0;
    }
    return 0;
}