# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjamie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 19:57:44 by sjamie            #+#    #+#              #
#    Updated: 2020/01/18 14:40:27 by bpole            ###   ########.fr        #
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
				  src/reader/check_file_content.c

LIB =			  ../libft/libft.a

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(LIB) $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -L ../libft -lft

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
