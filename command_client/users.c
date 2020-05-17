/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** users
*/

#include "client.h"

int users(char *answer)
{
    char **data = my_str_to_word_array_script((char *const)answer);

    for (int i = 1; data[i]; i++) {
        client_print_users("str", data[i], 0);
    }
    return (0);
}