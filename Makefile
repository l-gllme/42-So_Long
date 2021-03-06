# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguillau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 17:32:38 by lguillau          #+#    #+#              #
#    Updated: 2022/02/16 15:21:46 by lguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	so_long.c \
		tools/tools.c \
		tools/exit_game.c \
		tools/itoa.c \
		tools/img_protect.c \
		parsing/parsing.c \
		parsing/check_border.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		window/init_window.c \
		game/monsters.c \
		game/move.c \

S_PATH	=	srcs/
O_PATH	=	objs/
I_PATH	=	includes/
L_PATH	=	libx/

SRCS	=	${addprefix ${S_PATH}, ${FILES}}
OBJS	=	${addprefix ${O_PATH}, ${FILES:.c=.o}}

NAME	=	so_long

CC	=	clang

RM	=	rm -rf

CFLAGS	=	-Wall -Wextra -Werror -g3
LFLAGS	=	-lmlx_Linux -lXext -lX11

all:		${NAME}


${NAME}:	libx/libmlx_Linux.a ${OBJS}
		@${CC} ${OBJS} ${CFLAGS} -L ${L_PATH} ${LFLAGS}  -o ${NAME} -I ${I_PATH}
		@echo ""
		@echo "\e[36mBuilding\e[0m \e[40m$@\e[0m"
		@echo ""
		@echo "\e[3;32mCompilation is completed !\e[0m"

${O_PATH}%.o:	${S_PATH}%.c
		@mkdir -p ${dir $@}
		@${CC} ${CFLAGS} -c $< -o $@ -I ${I_PATH}
		@echo "\e[33mCompiling\e[0m \e[40m$<\e[0m \e[1;33m->\e[0m \e[94m$@\e[0m"

libx/libmlx_Linux.a:		
		make -C libx

lclean:		
		make clean -C libx


clean:		
		@${RM} ${O_PATH}
		@echo "\e[91mRemoving\e[0m \e[40m${O_PATH}\e[0m"

fclean:		lclean clean
		@${RM} ${NAME}
		@echo "\e[91mRemoving\e[0m \e[40m${NAME}\e[0m"
		
space:		
		@echo ""

re:		fclean space  all

.PHONY:		all clean fclean re libx
