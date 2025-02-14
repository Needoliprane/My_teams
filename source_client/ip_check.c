/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** ip_check
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validate_number(char *str)
{
    while (*str) {
        if (!isdigit(*str)){
            return (0);
        }
        str++;
    }
    return (1);
}

int validate_ip(char *ip)
{
    int num = 0;
    int dots = 0;
    char *ptr;

    ptr = strtok(ip, ".");
    if (ptr == NULL)
        return 84;
    while (ptr) {
        if (!validate_number(ptr))
            return 0;
        num = atoi(ptr);
        if (num >= 0 && num <= 255) {
            ptr = strtok(NULL, ".");
            if (ptr != NULL)
                dots++;
        } else
            return 84;
    }
    if (dots != 3)
        return 84;
    return 0;
}