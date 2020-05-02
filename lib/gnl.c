/*
** EPITECH PROJECT, 2020
** 4634731-6917058a9f6437092531794fa022aed8069e4aea
** File description:
** gnl
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <stdlib.h>

int read_from_stdin(char *read_buffer, size_t max_len)
{
    ssize_t read_count = 0;
    ssize_t total_read = 0;

    do {
        read_count = read(0, read_buffer, max_len);
        if (read_count < 0 && errno != EAGAIN && errno != EWOULDBLOCK) {
            return -1;
        }
        else if (read_count < 0 && (errno == EAGAIN || errno == EWOULDBLOCK)) {
            break;
        }
        else if (read_count > 0) {
            total_read += read_count;
            if ((int)total_read > (int)max_len) {
                fflush(STDIN_FILENO);
                break;
            }
        }
    } while (read_count > 0);
    if (strlen(read_buffer) > 0 && read_buffer[strlen(read_buffer) - 1] == '\n')
        read_buffer[strlen(read_buffer) - 1] = '\0';
    printf("Read from stdin %zu bytes. Let's prepare message to send.\n", strlen(read_buffer));
    return 0;
}