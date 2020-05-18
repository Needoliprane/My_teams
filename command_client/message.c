/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message
*/

#include "client.h"

int print_mp(char *answer)
{
    char **data = my_str_to_word_array_script((char *const)answer);

    client_private_message_print_messages(data[0], times(NULL), data[1]);
    return (0);
}