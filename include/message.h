/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message
*/

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

#define SENDER_MAXSIZE 128
#define DATA_MAXSIZE 512

typedef struct {
  char sender[SENDER_MAXSIZE];
  char data[DATA_MAXSIZE];
}  message_t;

int prepare_message(char *sender, char *data, message_t *message);
int print_message(message_t *message);
int validate_message_client(message_t *message);

#endif /* !MESSAGE_H_ */
