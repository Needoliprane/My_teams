/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** uuid
*/

#include <stdlib.h>
#include <stdio.h>
#include <uuid/uuid.h>

char *build_uuid()
{
    uuid_t binuuid;
    char *uuid = malloc(37);

    uuid_generate(binuuid);
    uuid_unparse(binuuid, uuid);
    return (uuid);
}