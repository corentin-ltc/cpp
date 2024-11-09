######################## SETTINGS ########################

NAME = human

CC = c++

FLAGS = -Wall -Wextra -Werror

EXTRAFLAGS = -std=c++98

INCLUDES =	includes \
			${foreach lib, ${LIBS}, ${lib} ${lib}/includes}

######################## SOURCES ########################


SRCS_NAMES =	main.cpp \
				Weapon.cpp \
				HumanA.cpp \
				HumanB.cpp

SRCS_DIR = srcs/

SRCS = ${addprefix ${SRCS_DIR}, ${SRCS_NAMES}}

OBJS_DIR = objs/

OBJS = ${addprefix ${OBJS_DIR}, ${SRCS_NAMES:.cpp=.o}}

######################## BASIC RULES ########################

all : 
	${MAKE} -j ${NAME}

re : fclean
	${MAKE} all

clean :
	${foreach lib, ${LIBS}, ${MAKE} clean -C ${lib}}
	rm -rf ${OBJS_DIR}

fclean : clean
	${foreach lib, ${LIBS}, ${MAKE} fclean -C ${lib}}
	rm -f ${NAME}

######################## COMPILATION ########################

${NAME} : ${OBJS_DIR} ${OBJS}
	${foreach lib, ${LIBS}, ${MAKE} -C ${lib}}
	${CC} ${FLAGS} ${OBJS} ${foreach lib, ${LIBS},${lib}/${lib}.a} -o $@ ${EXTRAFLAGS}

${OBJS_DIR} :
	mkdir $@

${OBJS_DIR}%.o : ${SRCS_DIR}%.cpp
	${CC} ${FLAGS} ${CPPFLAGS} ${foreach include, ${INCLUDES},-I ${include}} -c $< -o $@

######################## TEST ########################

test : base

base : all
	./${NAME}

leak : all
	valgrind --leak-check=full --show-leak-kinds=all ./${NAME}