/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** signal
*/

#include "sig_handle.h"
#include "server.h"

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

void shutdown_properly(int code)
{
    close(listen_sock);
    for (int i = 0; i < MAX_CLIENTS; ++i)
        if (connection_list[i].socket != NO_SOCKET)
            close(connection_list[i].socket);
    printf("Shutdown server properly.\n");
    exit(code);
}