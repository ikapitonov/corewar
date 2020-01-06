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

t_op	g_instr[COUNT_TOKENS + 1] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25, "load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25, "store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50, "long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

void			*smart_malloc(size_t how_much)
{
	void	*new;

	if (!(new = malloc(how_much)))
	{
		ft_putstr("malloc() does not work\n");
		exit(1);	
	}
	return (new);
}

static	void	init_reader(t_read *reader, int ch)
{
	int		i;

	i = 0;
	if (!(reader->str = file_get_contents(ch)))
		die("Empty file");
	reader->arr = ft_strsplit(reader->str, '\n');
	while (reader->arr[i])
		++i;
	reader->count = i;
	reader->i = 0;
	reader->j = 0;
}

void			*init(int ch)
{
	t_main	*main;

	main = (t_main*)smart_malloc(sizeof(t_main));
	main->reader = (t_read*)smart_malloc(sizeof(t_read));
	init_reader(main->reader, ch);
	main->name = NULL;
	main->last_token = NULL;
	main->comment = NULL;
	main->token = NULL;
	main->mark = NULL;
	main->last_mark = NULL;
	main->a_flag = 0;
	main->filename = NULL;
	buffer_init(&main->buffer, 100);
	return ((void*)main);
}
