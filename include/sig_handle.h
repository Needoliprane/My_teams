/*
** EPITECH PROJECT, 2020
** 4634731-6917058a9f6437092531794fa022aed8069e4aea
** File description:
** signal
*/

#ifndef SIGNAL_H_
#define SIGNAL_H_

#include <signal.h>

void shutdown_properly(int code);
void handle_signal_action(int sig_number);
int setup_signals();

#endif /* !SIGNAL_H_ */
