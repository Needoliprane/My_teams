/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channels
*/

#include "client.h"

int print_channels(char *answer)
{
    char **data = my_str_to_word_array_script((char *const)answer);

    for (int i = 1; data[i]; i++) {
        client_team_print_channels(server.uuid_user, data[i], answer);
    }
    return (0);
}