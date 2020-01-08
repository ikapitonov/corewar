# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjamie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 19:29:46 by sjamie            #+#    #+#              #
#    Updated: 2019/11/09 15:50:41 by matruman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

CC				= gcc
HEADER			= includes/
CFLAGS			= -Wall -Wextra -Werror -I $(HEADER)

SRC				=	src/ft_itoa_base.c\
					src/ft_printf.c\
					src/get_format.c\
					src/get_format_list.c\
					src/pf_helps.c\
					src/pf_helps1.c\
					src/print_conv_di.c\
					src/print_format.c\
					src/print_conv_pouxx.c\
					src/print_conv_cp.c\
					src/print_conv_s.c\
					src/get_fl.c\
					src/print_conv_float.c\
					src/buffer.c\
					src/long_arithmetic/big_int_print.c\
					src/long_arithmetic/la_helps.c\
					src/long_arithmetic/multiplication.c\
					src/long_arithmetic/pow_mult.c\
					src/long_arithmetic/read_long_long.c

LIB = libft/libft.a

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(LIB):
	make -C libft

clean:
	/bin/rm -f $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
