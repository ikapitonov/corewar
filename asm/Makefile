# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjamie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 19:57:44 by sjamie            #+#    #+#              #
#    Updated: 2019/11/12 19:57:45 by sjamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= asm

CC				= gcc
HEADER			= includes/
CFLAGS			= -I $(HEADER) #-Wall -Werror -Wextra -O2 -O3

SRC				= src/main.c \
				  src/init.c \
				  src/open.c \
				  src/calc/calc.c \
				\
				  src/coder/coder.c \
				  src/coder/buffer.c \
				  src/coder/helps.c \
				\
				  src/parser/parser.c \
				  src/parser/analysis.c \
				  src/parser/error/errors1.c \
				\
				  src/parser/reader/functions.c \
				  src/parser/reader/file_get_contents.c \
				\
				  src/parser/components/name_or_comment/name_or_comment.c \
				  src/parser/components/name_or_comment/full_string.c \
				\
				  src/parser/components/mark/is_mark.c \
				  src/parser/components/mark/mark.c \
				\
				  src/parser/components/token/token.c \
				  src/parser/components/token/new_token.c \
				  src/parser/components/token/registr.c \
				  src/parser/components/token/direct.c \
				  src/parser/components/token/indirect.c \
				  ../gnl/get_next_line.c

LIB = ../gnl/libft/libft.a
OBJ = $(patsubst %.c,%.o,$(SRC))

all: lib $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -L ../gnl/libft -lft

$(LIB):

lib:
	make -C ../gnl/libft

clean:
	/bin/rm -f $(OBJ)
	make -C ../gnl/libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ../gnl/libft fclean

re: fclean all

.PHONY: clean fclean all re
