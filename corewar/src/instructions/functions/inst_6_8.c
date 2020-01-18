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

int		bop_op(int a, int b, char op)
{
	if (op == '&')
		return (a & b);
	if (op == '|')
		return (a | b);
	if (op == '^')
		return (a ^ b);
	return (0);
}

void	bop_reg(t_cursor *cursor, char *area, char *mem, char op)
{ 
	if (cursor->types[1] == T_REG_CODE)
		{
			if (mem[1] > 16 || mem[2] > 16 || !mem[1] || !mem[2])
				return ;
			cursor->reg[mem[2] - 1] = bop_op(cursor->reg[mem[0] - 1],
			cursor->reg[mem[1] - 1], op);
			cursor->carry = !cursor->reg[mem[2] - 1];
			return;
		}
		if (cursor->types[1] == T_DIR_CODE)
		{
			if (mem[5] > 16 || !mem[5])
				return;
			cursor->reg[mem[5] - 1] = bop_op(*(int *)(mem + 1),
			cursor->reg[mem[0] - 1], op);
			cursor->carry = !cursor->reg[mem[5] - 1];
			return;
		}
		if (mem[3] > 16 || !mem[3])
			return;
		rev_endian (mem + 1, 2);
		memory_read(area, cursor->pos + *(short *)(mem + 1) / IDX_MOD,
		mem + 4, 4);
		cursor->reg[mem[3] - 1] = bop_op(*(int *)(mem + 4),
		cursor->reg[mem[0] - 1], op);
		cursor->carry = !cursor->reg[mem[3] - 1];
}

void	bop_dir(t_cursor *cursor, char *area, char *mem, char op)
{
	if (cursor->types[1] == T_REG_CODE)
		{
			if (mem[4] > 16 || mem[5] > 16 || !mem[4] || !mem[5])
				return ;
			cursor->reg[mem[5] - 1] = bop_op(*(int *)(mem),
			 cursor->reg[mem[4] - 1], op);
			cursor->carry = !cursor->reg[mem[5] - 1];
			return;
		}
		if (cursor->types[1] == T_DIR_CODE)
		{
			if (mem[8] > 16 || !mem[8])
				return;
			cursor->reg[mem[8] - 1] = bop_op(*(int *)(mem),
			*(int *)(mem + 4), op);
			cursor->carry = !cursor->reg[mem[8] - 1];
			return;
		}
		if (mem[6] > 16 || !mem[6])
			return;
		rev_endian (mem + 4, 2);
		memory_read(area, cursor->pos + *(short *)(mem + 1) / IDX_MOD,
		mem + 7, 4);
		cursor->reg[mem[6] - 1] = bop_op(*(int *)(mem),
		*(int *)(mem + 7), op);
		cursor->carry = !cursor->reg[mem[6] - 1];
}

void	bop_ind(t_cursor *cursor, char *area, char *mem, char op)
{
	if (cursor->types[1] == T_REG_CODE)
		{
			if (mem[2] > 16 || mem[3] > 16 || !mem[2] || !mem[3])
				return ;
			cursor->reg[mem[3] - 1] = bop_op(*(int *)(mem + 7),
			cursor->reg[mem[2] - 1], op);
			cursor->carry = !cursor->reg[mem[3] - 1];
			return;
		}
		if (cursor->types[1] == T_DIR_CODE)
		{
			if (mem[6] > 16 || !mem[6])
				return;
			cursor->reg[mem[6] - 1] = bop_op(*(int *)(mem + 7),
			*(int *)(mem + 2), op);
			cursor->carry = !cursor->reg[mem[6] - 1];
			return;
		}
		if (mem[4] > 16 || !mem[4])
			return;
		rev_endian (mem + 2, 2);
		memory_read(area, cursor->pos + *(short *)(mem + 2) / IDX_MOD,
		mem + 11, 4);
		cursor->reg[mem[4] - 1] = bop_op(*(int *)(mem + 7),
		*(int *)(mem + 11), op);
		cursor->carry = !cursor->reg[mem[4] - 1];
}

void    and(t_main *main, t_cursor *cursor, char *area)
{
	char	mem[15];
	char	op = '&';

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
		rev_endian (mem, 2);
		memory_read(area, cursor->pos + *(short *)(mem) / IDX_MOD,
		mem + 7, 4);
		bop_ind(cursor, area, mem, op);
	}
}

void    or(t_main *main, t_cursor *cursor, char *area)
{
	char	mem[15];
	char	op = '|';

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
		rev_endian (mem, 2);
		memory_read(area, cursor->pos + *(short *)(mem) / IDX_MOD,
		mem + 7, 4);
		bop_ind(cursor, area, mem, op);
	}
}

void    xor(t_main *main, t_cursor *cursor, char *area)
{
	char	mem[15];
	char	op = '^';

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
		rev_endian (mem, 2);
		memory_read(area, cursor->pos + *(short *)(mem) / IDX_MOD,
		mem + 7, 4);
		bop_ind(cursor, area, mem, op);
	}
}