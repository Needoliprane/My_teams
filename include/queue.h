/*
** EPITECH PROJECT, 2020
** 4634731-6917058a9f6437092531794fa022aed8069e4aea
** File description:
** queue
*/

#ifndef QUEUE_H_
#define QUEUE_H_

#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

#include "message.h"

typedef struct {
    int size;
    message_t *data;
    int current;
} message_queue_t;

int create_message_queue(int queue_size, message_queue_t *queue);
void delete_message_queue(message_queue_t *queue);
int enqueue(message_queue_t *queue, message_t *message);
int dequeue(message_queue_t *queue, message_t *message);
int dequeue_all(message_queue_t *queue);

#endif /* !QUEUE_H_ */
