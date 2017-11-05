##
## EPITECH PROJECT, 2017
## LibSharp
## File description:
## Makefile defining the building rules
##

NAME	=	libsharp.a

SRC	=	src/

CODE	=	$(SRC)list/create.c		\
		$(SRC)list/add.c		\
		$(SRC)list/print.c		\
		$(SRC)list/destroy.c		\
		$(SRC)list/remove.c		\
		$(SRC)list/swap.c		\
		$(SRC)list/import.c		\
		$(SRC)list/sort.c		\
		$(SRC)list/get.c		\
		$(SRC)list/search.c		\
		$(SRC)gc/malloc.c		\
		$(SRC)gc/free.c			\
		$(SRC)gc/realloc.c		\
		$(SRC)gc/print.c		\
		$(SRC)error_exit.c		\
		$(SRC)malloc_exit.c		\
		$(SRC)error_return.c		\
		$(SRC)error_ptr.c		\
		$(SRC)libsharp_error.c

OBJ	=	$(CODE:.c=.o)

INC	=	-I include/

CFLAGS	+=	-Ofast -Wall -Wextra -pedantic $(INC)

AR	=	ar rc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(AR) $(NAME) $(OBJ)


debug:		CFLAGS += -g
debug:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
