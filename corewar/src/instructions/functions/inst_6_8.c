/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_5_8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:40:55 by matruman          #+#    #+#             */
/*   Updated: 2020/01/13 21:33:17 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	and(t_main *main, t_cursor *cursor, char *area)
{
	uint8_t	mem[15];
	char	op;

	op = '&';
	(void)main;
	memory_read(area, cursor->pos + 2, mem, 9);
	if (cursor->types[0] == T_REG_CODE)
	{
		if (mem[0] > 16 || !mem[0])
			return ;
		bop_reg(cursor, area, mem, op);
	}
	if (cursor->types[0] == T_DIR_CODE)
	{
		bop_dir(cursor, area, mem, op);
	}
	if (cursor->types[0] == T_IND_CODE)
	{
		rev_endian(mem, 2);
		memory_read(area, cursor->pos + *(short *)(mem) % IDX_MOD,
		mem + 7, 4);
		bop_ind(cursor, area, mem, op);
	}
}

void	or(t_main *main, t_cursor *cursor, char *area)
{
	uint8_t	mem[15];
	char	op;

	op = '|';
	(void)main;
	memory_read(area, cursor->pos + 2, mem, 9);
	if (cursor->types[0] == T_REG_CODE)
	{
		if (mem[0] > 16 || !mem[0])
			return ;
		bop_reg(cursor, area, mem, op);
	}
	if (cursor->types[0] == T_DIR_CODE)
	{
		bop_dir(cursor, area, mem, op);
	}
	if (cursor->types[0] == T_IND_CODE)
	{
		rev_endian(mem, 2);
		memory_read(area, cursor->pos + *(short *)(mem) % IDX_MOD,
		mem + 7, 4);
		bop_ind(cursor, area, mem, op);
	}
}

void	xor(t_main *main, t_cursor *cursor, char *area)
{
	uint8_t	mem[15];
	char	op;

	op = '^';
	(void)main;
	memory_read(area, cursor->pos + 2, mem, 9);
	if (cursor->types[0] == T_REG_CODE)
	{
		if (mem[0] > 16 || !mem[0])
			return ;
		bop_reg(cursor, area, mem, op);
	}
	if (cursor->types[0] == T_DIR_CODE)
	{
		bop_dir(cursor, area, mem, op);
	}
	if (cursor->types[0] == T_IND_CODE)
	{
		rev_endian(mem, 2);
		memory_read(area, cursor->pos + *(short *)(mem) % IDX_MOD,
		mem + 7, 4);
		bop_ind(cursor, area, mem, op);
	}
}
