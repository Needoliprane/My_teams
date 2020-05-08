/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** sig_handle
*/

#ifndef SIGNAL_H_
#define SIGNAL_H_

#include <signal.h>

void shutdown_properly(int code);
void handle_signal_action(int sig_number);
int setup_signals();

#endif /* !SIGNAL_H_ */
