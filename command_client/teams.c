/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** teams
*/

#include "client.h"

int print_teams(char *answer)
{
    char **data = my_str_to_word_array_script((char *const)answer);

    for (int i = 1; data[i]; i++) {
        client_print_teams(server.uuid_user, data[i], 0);
    }
    return (0);
}