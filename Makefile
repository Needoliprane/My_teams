##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME	=	myteams_cli

NAME2	=	myteams_server

SRC	=	srcclient/main.c						\
		srcclient/get_next_line.c				\
		srcclient/master.c						\
		srcclient/shell.c						\
		srcclient/command_user.c				\
		srcclient/help.c						\
		srcclient/my_str_to_word_array_shell.c	\
		common/packet.c							\

SRC2 =	srcserveur/main.c			\
		common/packet.c				\

OBJ	=	$(SRC:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

CPPFLAGS=	-I./include

CC	=	gcc -Wall -Wextra -g3

RM	=	rm -f

all:	nm	objdump

nm:	$(OBJ)
	$(CC) -g3 $(OBJ) -o $(NAME)

objdump:	$(OBJ2)
	$(CC) -g3 $(OBJ2) -o $(NAME2)

clean:
	$(RM) $(OBJ) $(OBJ2)

fclean: clean
	$(RM) $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
