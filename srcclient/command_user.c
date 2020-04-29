/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_user
*/

#include "client.h"

int login(client_user_t *user, char *check, int sock)
{
    char **data = my_str_to_word_array_script(check);

    if (data[1] != NULL) {
        user->user = strdup(data[1]);
        return (0);
    }
    free_tab(data);
    printf("Error login\n");
    return (0);
}

int logout(client_user_t *user, char *check, int sock)
{
    return (84);
}