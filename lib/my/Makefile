##
## EPITECH PROJECT, 2017
## my
## File description:
## Makefile
##

NAME	=	../libmy.a

SRC	=	my_fprintf.c \
		my_getline.c \
		my_strcmp.c \
		my_strncpy.c \
		my_strdup.c \
		my_strlen.c \
		my_strncat.c \
		my_str_to_tab.c \
		add_line.c \
		concat.c \
		my_atoi.c \
		my_str_to_unsigned_int.c \
		my_str_to_float.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I../../include
CFLAGS	+=	-W -Wall -Wextra

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@ar rc $(NAME) $(OBJ)

clean	:
		@rm -f $(OBJ)

fclean	:	clean
		@rm -f $(NAME)

re	:	fclean all
