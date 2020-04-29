/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** packet
*/

#ifndef PACKET_H_
#define PACKET_H_

typedef struct packet_s {
    bool isChannel;
    bool isTeams;
    bool isCreating;
    char *user;
    char *message;
    char *dest;
} packet_t;


char *struct_to_txt(packet_t *pack);
packet_t *txt_to_struct(char *packet_string);

#endif /* !PACKET_H_ */
