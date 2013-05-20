CC		= g++

RM		= rm -f

NAME		= BomberMan

CPPFLAGS	+= -W -Wall -Wextra
CPPFLAGS	+= -I

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
