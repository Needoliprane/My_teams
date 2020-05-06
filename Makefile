##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME	=	myteams_cli

NAME2	=	myteams_server

SRC_LIB =	lib/gnl.c								\
			lib/message.c							\
			lib/queue.c								\
			lib/my_str_to_word_array_shell.c		\
			lib/strcat.c							\
			lib/receive_peer.c						\
			lib/send_peer.c							\
			lib/create_peer.c						\
			lib/delete_peer.c						\
			lib/get_add_peer.c						\
			lib/peer_add_to_send.c					\

SRC	=	source_client/client.c			\
		source_client/ip_check.c		\
		source_client/main.c			\
		source_client/read.c			\
		source_client/recive.c			\
		source_client/signal.c			\

SRC2 =	source_server/handle_connection.c	\
		source_server/main.c				\
		source_server/read.c				\
		source_server/recive.c				\
		source_server/server.c				\
		source_server/signal.c				\

OBJ	=	$(SRC:.c=.o)

OBJ_LIB	=	$(SRC_LIB:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

CPPFLAGS=	-I./include

CC	=	gcc -Wall -Wextra -g3

RM	=	rm -f

all:	nm	objdump

nm:	$(OBJ) $(OBJ_LIB)
	$(CC) -g3 $(OBJ) $(OBJ_LIB) -o $(NAME)

objdump:	$(OBJ2) $(OBJ_LIB)
	$(CC) -g3 $(OBJ2) $(OBJ_LIB) -o $(NAME2)

clean:
	$(RM) $(OBJ) $(OBJ2) $(OBJ_LIB)

fclean: clean
	$(RM) $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
