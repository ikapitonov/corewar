# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjamie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 19:57:44 by sjamie            #+#    #+#              #
#    Updated: 2020/01/17 17:37:09 by bpole            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= corewar

CC				= gcc
HEADER			= includes/

CFLAGS			= -I $(HEADER) #-Wall -Werror -Wextra -O2 -O3

SRC				= src/main.c \
				  src/init.c \
				  src/memory/memory_rw.c \
				  src/reader/params.c \
				  src/reader/is_valid.c \
				  src/reader/player.c \
				  src/reader/check_file_content.c \
				  \
				  src/instructions/functions/inst_1_5.c \
				  src/instructions/functions/inst_6_8.c \
				  src/instructions/functions/inst_9_12.c \
				  src/instructions/functions/inst_13_16.c \
				  \
				  src/visual/control.c \
				  src/visual/corewar_loop.c \
				  src/visual/print_memory.c \
				  src/visual/render.c \
				  src/visual/render_inst.c \
				  \
				  src/game/game.c

LIB =			  ../libft/libft.a

OBJ = $(patsubst %.c,%.o,$(SRC))

FRAEM = -lmlx -framework OpenGL -framework AppKit

all: $(LIB) $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(FRAEM) -L ../libft -lft

$(LIB):
	make -C ../libft

clean:
	/bin/rm -f $(OBJ)
	make -C ../libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ../libft fclean

re: fclean all

.PHONY: clean fclean all re
