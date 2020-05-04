/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** strcat
*/

#include <stdlib.h>

char *my_strcat(char *buf, char *tmp)
{
    int j = 0;
    int len1 = strlen(buf);
    char *new_tmp = malloc(sizeof(char) * (len1 + strlen(tmp) + 1));

    if (new_tmp == NULL)
        return (NULL);
    for (;buf[j]; j++)
        new_tmp[j] = buf[j];
    for (int i = 0; tmp[i]; j++, i++)
        new_tmp[j] = tmp[i];
    new_tmp[j] = '\0';
    return (new_tmp);
}