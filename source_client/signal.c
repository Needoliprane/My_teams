/*
** EPITECH PROJECT, 2020
** 4634731-6917058a9f6437092531794fa022aed8069e4aea
** File description:
** signal
*/

#include "signal_client.h"
#include "client.h"
#include "peer.h"

void shutdown_properly(int code)
{
    delete_peer(&server);
    printf("Shutdown client properly.\n");
    exit(code);
}

void handle_signal_action(int sig_number)
{
    if (sig_number == SIGINT) {
        printf("SIGINT was catched!\n");
        shutdown_properly(EXIT_SUCCESS);
    } else if (sig_number == SIGPIPE) {
        printf("SIGPIPE was catched!\n");
        shutdown_properly(EXIT_SUCCESS);
    }
}

int setup_signals()
{
    struct sigaction sa;

    sa.sa_handler = handle_signal_action;
    if (sigaction(SIGINT, &sa, 0) != 0) {
        return -1;
    }
    if (sigaction(SIGPIPE, &sa, 0) != 0) {
        return -1;
    }
    return 0;
}