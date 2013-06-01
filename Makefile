CC          = g++

RM          = rm -f

NAME		= BomberMan

CPPFLAGS	+= -W -Wall -Wextra

CPPFLAGS	+= -I./inc/
CPPFLAGS	+= -I./inc/Core/
CPPFLAGS	+= -I./inc/DataFormat/
CPPFLAGS	+= -I./inc/Display/
CPPFLAGS	+= -I./inc/Field/
CPPFLAGS	+= -I./inc/Unix/
CPPFLAGS	+= -I./libgdl/include
CPPFLAGS	+= -I./inc/Input/ -I./inc/Input/Controller/
CPPFLAGS	+= -I./inc/Event/

LDFLAGS		=  -lpthread -L./libgdl/lib -Wl,--rpath=./libgdl/lib -lgdl_gl -lGL -lGLU -lopencv_imgproc -lopencv_highgui

SRC_DIR		= src/

CORE        = Core/
DATAFORMAT  = DataFormat/
DISPLAY     = Display/
FIELD       = Field/
INPUT	    = Input/
CONTROLLER  = Controller/
EVENT	    = Event/
UNIX        = Unix/

SRCS		= $(SRC_DIR)main.cpp \

SRCS_CORE	= $(SRC_DIR)$(CORE)BomberMan.cpp \
		$(SRC_DIR)$(CORE)BomberGame.cpp \
		$(SRC_DIR)$(CORE)EndOfBomberMan.cpp \

SRCS_DATA	= $(SRC_DIR)$(DATAFORMAT)ADataFormat.cpp \
		$(SRC_DIR)$(DATAFORMAT)FormatError.cpp \
		$(SRC_DIR)$(DATAFORMAT)Parser.cpp \
		$(SRC_DIR)$(DATAFORMAT)Xml.cpp \

SRCS_DISPLAY	= $(SRC_DIR)$(DISPLAY)AAnimation.cpp \
		$(SRC_DIR)$(DISPLAY)MenuManager.cpp \
		$(SRC_DIR)$(DISPLAY)MainMenu.cpp \
		$(SRC_DIR)$(DISPLAY)Game.cpp \
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
		$(SRC_DIR)$(DISPLAY)Camera.cpp

SRCS_FIELD	= $(SRC_DIR)$(FIELD)AGameComponent.cpp \
		$(SRC_DIR)$(FIELD)Empty.cpp \
		$(SRC_DIR)$(FIELD)FieldError.cpp \
		$(SRC_DIR)$(FIELD)Object.cpp \
		$(SRC_DIR)$(FIELD)ObjectFactory.cpp \
		$(SRC_DIR)$(FIELD)Player.cpp \
		$(SRC_DIR)$(FIELD)Wall.cpp \
		$(SRC_DIR)$(FIELD)FManager.cpp

SRCS_INPUT	= $(SRC_DIR)$(INPUT)InputManager.cpp \
		$(SRC_DIR)$(INPUT)InputError.cpp \

SRCS_CTLLR	= $(SRC_DIR)$(INPUT)$(CONTROLLER)KeyBoardManager.cpp \
		$(SRC_DIR)$(INPUT)$(CONTROLLER)XBoxController.cpp \
		$(SRC_DIR)$(INPUT)$(CONTROLLER)ControllerError.cpp \

SRCS_EVENT	= $(SRC_DIR)$(EVENT)AEvent.cpp \
		$(SRC_DIR)$(EVENT)EventManager.cpp \
		$(SRC_DIR)$(EVENT)EventError.cpp \
		$(SRC_DIR)$(EVENT)Move.cpp \

SRCS_UNIX	= $(SRC_DIR)$(UNIX)UnixMutex.cpp \
		$(SRC_DIR)$(UNIX)UnixThread.cpp \
		$(SRC_DIR)$(UNIX)ThreadPool.cpp \
		$(SRC_DIR)$(UNIX)Fd.cpp \

OBJS		= $(SRCS:.cpp=.o) \
		$(SRCS_CORE:.cpp=.o) \
		$(SRCS_DATA:.cpp=.o) \
		$(SRCS_DISPLAY:.cpp=.o) \
		$(SRCS_FIELD:.cpp=.o) \
		$(SRCS_UNIX:.cpp=.o) \
		$(SRCS_INPUT:.cpp=.o) \
		$(SRCS_CTLLR:.cpp=.o) \
		$(SRCS_EVENT:.cpp=.o) \

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean
