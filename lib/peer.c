/*
** EPITECH PROJECT, 2020
** 4634731-6917058a9f6437092531794fa022aed8069e4aea
** File description:
** peer
*/

#include <unistd.h>
#include "peer.h"

int delete_peer(peer_t *peer)
{
    close(peer->socket);
    delete_message_queue(&peer->send_buffer);
    return (0);
}

int create_peer(peer_t *peer)
{
    create_message_queue(MAX_MESSAGES_BUFFER_SIZE, &peer->send_buffer);
    peer->current_sending_byte = -1;
    peer->current_receiving_byte = 0;
    return 0;
}

char *peer_get_addres_str(peer_t *peer)
{
    static char ret[INET_ADDRSTRLEN + 10];
    char peer_ipv4_str[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &peer->addres.sin_addr, peer_ipv4_str, INET_ADDRSTRLEN);
    sprintf(ret, "%s:%d", peer_ipv4_str, peer->addres.sin_port);
    return ret;
}

int peer_add_to_send(peer_t *peer, message_t *message)
{
    return enqueue(&peer->send_buffer, message);
}

int receive_from_peer(peer_t *peer, int (*message_handler)(message_t *))
{
    size_t len_to_receive;
    ssize_t received_count;
    size_t received_total = 0;

    do {
        if (peer->current_receiving_byte >= sizeof(peer->receiving_buffer)) {
            message_handler(&peer->receiving_buffer);
            peer->current_receiving_byte = 0;
        }
      len_to_receive = sizeof(peer->receiving_buffer) - peer->current_receiving_byte;
      if (len_to_receive > MAX_SEND_SIZE)
          len_to_receive = MAX_SEND_SIZE;
      received_count = recv(peer->socket, (char *)&peer->receiving_buffer + peer->current_receiving_byte, len_to_receive, MSG_DONTWAIT);
      if (received_count < 0) {
          if (errno == EAGAIN || errno == EWOULDBLOCK) {
          } else {
              return -1;
          }
      }  else if (received_count < 0 && (errno == EAGAIN || errno == EWOULDBLOCK)) {
          break;
      } else if (received_count == 0) {
          return -1;
      } else if (received_count > 0) {
          peer->current_receiving_byte += received_count;
          received_total += received_count;
      }
    } while (received_count > 0);
    return 0;
}

int send_to_peer(peer_t *peer)
{
    size_t len_to_send;
    ssize_t send_count;
    size_t send_total = 0;

    do {
        if (peer->current_sending_byte >= sizeof(peer->sending_buffer)) {
            if (dequeue(&peer->send_buffer, &peer->sending_buffer) != 0) {
                peer->current_sending_byte = -1;
                break;
            }
            peer->current_sending_byte = 0;
        }
        len_to_send = sizeof(peer->sending_buffer) - peer->current_sending_byte;
        if (len_to_send > MAX_SEND_SIZE)
            len_to_send = MAX_SEND_SIZE;
        send_count = send(peer->socket, (char *)&peer->sending_buffer + peer->current_sending_byte, len_to_send, 0);
        if (send_count < 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
            } else {
                return -1;
            }
        } else if (send_count < 0 && (errno == EAGAIN || errno == EWOULDBLOCK)) {
            break;
        } else if (send_count == 0) {
            break;
        } else if (send_count > 0) {
            peer->current_sending_byte += send_count;
            send_total += send_count;
        }
    } while (send_count > 0);
    return 0;
}