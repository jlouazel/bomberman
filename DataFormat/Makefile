CC		= g++

RM		= rm -f

NAME		= parser

CPPFLAGS	+= -W -Wall -Wextra
CPPFLAGS	+= -I ./includes

SRC_DIR		= sources/

SRCS		= $(SRC_DIR)parser.cpp \
		$(SRC_DIR)ADataFormat.cpp \
		$(SRC_DIR)Parser.cpp \
		$(SRC_DIR)Error.cpp \
		$(SRC_DIR)Xml.cpp

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
