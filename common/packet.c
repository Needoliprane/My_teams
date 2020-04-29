/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** packet
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "packet.h"

char *my_strcat(char *src1, char *src2)
{
    char *value = malloc(sizeof(char) * (strlen(src1) + strlen(src2) + 1));
    int i = 0;
    int j = 0;

    for (i = 0; src1[i];value[i] = src1[i], i++);
    for (j = 0; src2[j]; value[i] = src2[j], i++, j++);
    value[i] = '\0';
    return (value);
}

void extract_between_quotes(char* s, char* dest)
{
   int in_quotes = 0;
   *dest = 0;
   while(*s != 0)
   {
      if(in_quotes)
      {
         if(*s == '"') return;
         dest[0]=*s;
         dest[1]=0;
         dest++;
      }
      else if(*s == '"') in_quotes=1;
      s++;
   }
}

char *my_cut(char *str, int size)
{
    char *dest = malloc(sizeof(char) * (size + 1));

    for (int i = 0; i <= size; dest[i] = '\0', i++);
    extract_between_quotes(str, dest);
    return (dest);
}

char *struct_to_txt(packet_t *pack)
{
    char *packet = my_strcat("{\n\t\"isChannel\" : \"", "");

    packet = my_strcat(packet, (pack->isChannel == true) ? "True\",\n" : "False\",\n");
    packet = my_strcat(packet, "\t\"isTeams\" : \"");
    packet = my_strcat(packet, (pack->isTeams == true) ? "True\",\n" : "False\",\n");
    packet = my_strcat(packet, "\t\"user\" : \"");
    packet = my_strcat(packet, pack->user);
    packet = my_strcat(packet, "\",\n\t\"isCreating\" : \"");
    packet = my_strcat(packet, (pack->isCreating == true) ? "True\",\n" : "False\",\n");
    packet = my_strcat(packet, "\t\"message\" : \"");
    packet = my_strcat(packet, pack->message);
    packet = my_strcat(packet, "\",\n\t\"dest\" : \"");
    packet = my_strcat(packet, pack->dest);
    packet = my_strcat(packet, "\",\n}");
    return (packet);
}

packet_t *txt_to_struct(char *packet_string)
{
    packet_t *packet = malloc(sizeof(packet_t));
    char *tmp = strstr(packet_string, "isChannel");
    int check = 0;

    check = strcmp(my_cut(tmp + strlen("isChannel") + 1, 5), "False");
    packet->isChannel = (check == 0) ? false : true;
    tmp = strstr(packet_string, "isTeams");
    check = strcmp(my_cut(tmp + strlen("isTeams") + 1, 5), "False");
    packet->isTeams = (check == 0) ? false : true;
    tmp = strstr(packet_string, "isCreating");
    check = strcmp(my_cut(tmp + strlen("isCreating") + 1, 5), "False");
    packet->isCreating = (check == 0) ? false : true;
    tmp = strstr(packet_string, "user");
    packet->user = strdup(my_cut(tmp + strlen("user") + 1, 32));
    tmp = strstr(packet_string, "message");
    packet->message = strdup(my_cut(tmp + strlen("message") + 1, 524));
    tmp = strstr(packet_string, "dest");
    packet->dest = strdup(my_cut(tmp + strlen("user") + 1, 32));
    return (packet);
}