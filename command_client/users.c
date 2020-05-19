/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** users
*/

#include "client.h"

int print_users(char *answer)
{
    char **data = my_str_to_word_array((char *const)answer);

    for (int i = 1; data[i]; i += 2) {
        client_print_users(data[i + 1], data[i], 1);
    }
    return (0);
}