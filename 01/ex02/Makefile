######################## SETTINGS ########################

NAME = main

CC = c++

FLAGS = -Wall -Wextra -Werror

EXTRAFLAGS = -std=c++98

INCLUDES =	includes \
			${foreach lib, ${LIBS}, ${lib} ${lib}/includes}

######################## SOURCES ########################


SRCS_NAMES =	main.cpp

SRCS_DIR = ./

SRCS = ${addprefix ${SRCS_DIR}, ${SRCS_NAMES}}

OBJS_DIR = ./

OBJS = ${addprefix ${OBJS_DIR}, ${SRCS_NAMES:.cpp=.o}}

######################## BASIC RULES ########################

all : 
	${MAKE} -j ${NAME}

re : fclean
	${MAKE} all

clean :
	rm -rf ${NAME}.o

fclean : clean
	rm -rf ${NAME}
	

######################## COMPILATION ########################

${NAME} : ${OBJS_DIR} ${OBJS}
	${foreach lib, ${LIBS}, ${MAKE} -C ${lib}}
	${CC} ${FLAGS} ${OBJS} ${foreach lib, ${LIBS},${lib}/${lib}.a} -o $@ ${EXTRAFLAGS}

debug : ${OBJS_DIR} ${OBJS}
	${foreach lib, ${LIBS}, ${MAKE} -C ${lib}}
	${CC} ${FLAGS} -g3 -fsanitize=address ${OBJS} ${foreach lib, ${LIBS},${lib}/${lib}.a} -o ${NAME} ${EXTRAFLAGS}

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