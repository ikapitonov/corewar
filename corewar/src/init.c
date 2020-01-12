/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 20:05:58 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/12 18:22:09 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

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

void			init_area(t_main *main)
{
	int		constant;
	int		start;
	int		i;

	constant = MEM_SIZE / main->players;
	start = START_COMMENT + COMMENT_LENGTH + NULL_SIZE;
	i = 0;
	while (i < main->players)
	{
		if (main->player[i].code_size)
		{
			ft_memcpy(main->area + (i * constant),
				main->player[i].content + start,
				main->player[i].code_size);
		}
		++i;
	}
}

void			init_cursors(t_main *main)
{
	t_cursor	*cursor;
	int			constant;
	int			i;
	int			j;

	i = 0;
	constant = MEM_SIZE / main->players;
	while (i < main->players)
	{
		cursor = (t_cursor*)smart_malloc(sizeof(t_cursor));
		cursor->pos = i * constant;
		cursor->carry = 0;
		cursor->registers[0] = main->player[i].id;
		j = 1;
		while (j < REG_NUMBER)
		{
			cursor->registers[j] = 0;
			++j;
		}
		cursor->next = main->cursor;
		main->cursor = cursor;
		++i;
	}
}

static	void	init_players(t_main *main)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		main->player[i].content = NULL;
		main->player[i].file_size = 0;
		main->player[i].code_size = 0;
		main->player[i].id = 0;
		++i;
	}
}

void			*init()
{
	t_main	*main;

	main = (t_main*)smart_malloc(sizeof(t_main));
	main->players = 0;
	main->cursor = NULL;
	main->last_cursor = NULL;
	if (!(main->area = (char*)ft_memalloc(sizeof(char) * (MEM_SIZE + 1))))
		die("malloc() does not work");
	main->area[MEM_SIZE] = 0;
	main->dump = 0;
	init_players(main);
	return ((void*)main);
}
