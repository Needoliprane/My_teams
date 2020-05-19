##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME	=	myteams_cli

NAME2	=	myteams_server

SRC_LIB =	lib/gnl.c									\
			lib/message.c								\
			lib/queue.c									\
			lib/my_str_to_word_array_shell.c			\
			lib/strcat.c								\
			lib/receive_peer.c							\
			lib/send_peer.c								\
			lib/create_peer.c							\
			lib/delete_peer.c							\
			lib/get_add_peer.c							\
			lib/peer_add_to_send.c						\
			lib/uuid.c									\

SRC_COMMAND_SERVER	=	command_serveur/error.c			\
						command_serveur/help.c			\
						command_serveur/login.c			\
						command_serveur/send.c			\
						command_serveur/users.c			\
						command_serveur/user.c			\
						command_serveur/messages.c		\
						command_serveur/create.c		\
						command_serveur/list.c			\
						command_serveur/use.c			\

SRC_COMMAND_CLIENT	=	command_client/users.c			\

SRC	=	source_client/client.c							\
		source_client/ip_check.c						\
		source_client/main.c							\
		source_client/read.c							\
		source_client/recive.c							\
		source_client/signal.c							\

SRC2 =	source_server/handle_connection.c				\
		source_server/main.c							\
		source_server/read.c							\
		source_server/recive.c							\
		source_server/server.c							\
		source_server/signal.c							\

OBJ	=	$(SRC:.c=.o)

OBJ_LIB	=	$(SRC_LIB:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

OBJ_COMMAND_SERV	=	$(SRC_COMMAND_SERVER:.c=.o)

OBJ_COMMAND_CLIENT	=	$(SRC_COMMAND_CLIENT:.c=.o)

CPPFLAGS=	-I./include

CC	=	gcc -Wall -Wextra -g3 -Wno-unused-parameter -luuid

RM	=	rm -f

all:	nm	objdump

nm:	$(OBJ) $(OBJ_LIB) $(OBJ_COMMAND_CLIENT)
	$(CC) -g3 $(OBJ) $(OBJ_LIB) -o $(NAME) -L$(PWD)/libs/myteams/ -lmyteams

objdump:	$(OBJ2) $(OBJ_LIB) $(OBJ_COMMAND_SERV)
	$(CC) -g3 $(OBJ2) $(OBJ_LIB) $(OBJ_COMMAND_SERV) -o $(NAME2) -L$(PWD)/libs/myteams/ -lmyteams

clean:
	$(RM) $(OBJ) $(OBJ2) $(OBJ_LIB) $(OBJ_COMMAND_SERV) libmyteams.so $(OBJ_COMMAND_CLIENT)

fclean: clean
	$(RM) $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
