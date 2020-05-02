/*
** EPITECH PROJECT, 2020
** 4634731-6917058a9f6437092531794fa022aed8069e4aea
** File description:
** signal_server
*/

#ifndef SIGNAL_SERVER_H_
#define SIGNAL_SERVER_H_

void handle_signal_action(int sig_number);
int setup_signals();
void shutdown_properly(int code);

#endif /* !SIGNAL_SERVER_H_ */
