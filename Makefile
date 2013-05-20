CC          = g++

RM          = rm -f

NAME		= BomberMan

CPPFLAGS	+= -W -Wall -Wextra
CPPFLAGS	+= -Iinc/Controller inc/Core inc/DataFormat inc/Display inc/Event inc/Field inc/Unix inc

SRC_DIR		= sources/

SRCS		= 

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean
