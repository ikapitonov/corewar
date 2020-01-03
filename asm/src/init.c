/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:31:52 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/03 17:31:53 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_op	g_instr[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};
     void p(void) {printf("HELLO\n");}

void			error_position(char *first, char *second, int i, int j)
{
	int		fd;
	int		tmp;

	fd = 1;
	write(fd, first, ft_strlen(first));
	write(fd, "[", 1);
	tmp = 100;
	while (tmp / 10 && tmp > i)
	{
		write(fd, "0", 1);
		tmp /= 10;
	}
	ft_putnbr_fd(i, fd);
	write(fd, ":", 1);
	tmp = 100;
	while (tmp / 10 && tmp > j)
	{
		write(fd, "0", 1);
		tmp /= 10;
	}
	ft_putnbr_fd(j, fd);
	write(fd, "]", 1);
	if (second && second[0])
		write(fd, second, ft_strlen(second));
	write(fd, "\n", 1);
	exit(1);
}

void			die(const char *reason)
{
	int		fd;

	fd = 1;
	write(fd, reason, ft_strlen(reason));
	write(fd, "\n", 1);
	exit(1);
}

void			*smart_malloc(size_t how_much)
{
	void	*new;

	if (!(new = malloc(how_much)))
	{
		ft_putstr("malloc() does not work");
		exit(1);	
	}
	return (new);
}

void			*init()
{
	t_main	*main;

	main = (t_main*)smart_malloc(sizeof(t_main));
	main->lines = 0;
	main->name = NULL;
	main->comment = NULL;
	main->token = NULL;
	main->mark = NULL;
	return ((void*)main);
}
