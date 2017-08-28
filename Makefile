##
## Makefile for LibSharp in /home/myujinn/Liebrary
## 
## Made by Victor LE DANTEC
## Login   <victor.le-dantec@epitech.eu>
## 
## Started on  Mon Aug 21 19:40:04 2017 Victor LE DANTEC
## Last update Sun Aug 27 20:37:56 2017 Victor LE DANTEC
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
		$(SRC)error_exit.c		\
		$(SRC)malloc_exit.c

OBJ	=	$(CODE:.c=.o)

INC	=	-I include/

CFLAGS	+=	-Ofast -Wall -Wextra -pedantic $(INC) -g

AR	=	ar rc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(AR) $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re