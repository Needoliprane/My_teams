/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** signal
*/

#include "sig_handle.h"
#include "client.h"
#include "peer.h"

void shutdown_properly(int code)
{
    delete_peer(&server);
    printf("shutdown clean\n");
    exit(code);
}

void handle_signal_action(int sig_number)
{
    if (sig_number == SIGINT)
        shutdown_properly(EXIT_SUCCESS);
    else if (sig_number == SIGPIPE)
        shutdown_properly(EXIT_SUCCESS);
}

int setup_signals()
{
    struct sigaction sa;

    sa.sa_handler = handle_signal_action;
    if (sigaction(SIGINT, &sa, 0) != 0)
        return -1;
    if (sigaction(SIGPIPE, &sa, 0) != 0)
        return -1;
    return 0;
}