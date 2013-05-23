CC          = g++

RM          = rm -f

NAME		= BomberMan

CPPFLAGS	+= -W -Wall -Wextra
CPPFLAGS	+= -Iinc/Controller/ -Iinc/Core/ -Iinc/DataFormat/ -Iinc/Display/ -Iinc/Event/ -Iinc/Field/ -Iinc/Unix/ -Iinc/ -I./libgdl/include
LDFLAGS		=  -lpthread -L./libgdl/lib -Wl,--rpath=./libgdl/lib -lgdl_gl -lGL -lGLU

SRC_DIR		= src/
CONTROLLER  = Controller/
CORE        = Core/
DATAFORMAT  = DataFormat/
DISPLAY     = Display/
EVENT       = Event/
FIELD       = Field/
UNIX        = Unix/

SRCS		= $(SRC_DIR)BomberMan.cpp \
            $(SRC_DIR)$(CONTROLLER)AController.cpp \
            $(SRC_DIR)$(CONTROLLER)Controller.cpp \
            $(SRC_DIR)$(CONTROLLER)ControllerError.cpp \
            $(SRC_DIR)$(CORE)CoreError.cpp \
            $(SRC_DIR)$(DATAFORMAT)ADataFormat.cpp \
            $(SRC_DIR)$(DATAFORMAT)FormatError.cpp \
            $(SRC_DIR)$(DATAFORMAT)Parser.cpp \
            $(SRC_DIR)$(DATAFORMAT)Xml.cpp \
            $(SRC_DIR)$(DISPLAY)AAnimation.cpp \
            $(SRC_DIR)$(DISPLAY)AObject.cpp \
            $(SRC_DIR)$(DISPLAY)Menu.cpp \
            $(SRC_DIR)$(DISPLAY)OngletMenu.cpp \
            $(SRC_DIR)$(DISPLAY)Texture2d.cpp \
            $(SRC_DIR)$(DISPLAY)Texture3d.cpp \
            $(SRC_DIR)$(DISPLAY)Vector.cpp \
            $(SRC_DIR)$(DISPLAY)AAsset.cpp \
            $(SRC_DIR)$(DISPLAY)APicture.cpp \
            $(SRC_DIR)$(DISPLAY)ASound.cpp \
            $(SRC_DIR)$(DISPLAY)DisplayError.cpp \
            $(SRC_DIR)$(DISPLAY)GDLAnimation.cpp \
            $(SRC_DIR)$(DISPLAY)GDLAsset.cpp \
            $(SRC_DIR)$(DISPLAY)GDLSound.cpp \
            $(SRC_DIR)$(DISPLAY)GDLPicture.cpp \
            $(SRC_DIR)$(DISPLAY)Manager.cpp \
            $(SRC_DIR)$(DISPLAY)Resources.cpp \
            $(SRC_DIR)$(EVENT)AEvent.cpp \
            $(SRC_DIR)$(EVENT)EventError.cpp \
            $(SRC_DIR)$(EVENT)Event.cpp \
            $(SRC_DIR)$(EVENT)EventFactory.cpp \
            $(SRC_DIR)$(EVENT)Manager.cpp \
            $(SRC_DIR)$(FIELD)AGameComponent.cpp \
            $(SRC_DIR)$(FIELD)Empty.cpp \
            $(SRC_DIR)$(FIELD)FieldError.cpp \
            $(SRC_DIR)$(FIELD)Field.cpp \
            $(SRC_DIR)$(FIELD)Object.cpp \
            $(SRC_DIR)$(FIELD)ObjectFactory.cpp \
            $(SRC_DIR)$(FIELD)Player.cpp \
            $(SRC_DIR)$(FIELD)Wall.cpp \
            $(SRC_DIR)$(UNIX)UnixMutex.cpp \
            $(SRC_DIR)$(UNIX)UnixThread.cpp \
            $(SRC_DIR)$(UNIX)ThreadPool.cpp

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean
