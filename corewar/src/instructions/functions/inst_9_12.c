/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_9_12.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:41:22 by matruman          #+#    #+#             */
/*   Updated: 2020/01/13 15:59:33 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			zjmp(t_main *main, t_cursor *cursor, char *area)
{
	int16_t	addr;
	
	(void)main;
	memory_read(area, cursor->pos + 1, &addr, 2);
	rev_endian(&addr, 2);
	if (cursor->carry)
	{
		cursor->pos += addr % IDX_MOD;
		if (cursor->pos < 0)
			cursor->pos += MEM_SIZE;
		if (addr % IDX_MOD == 0)
			cursor->pos = (cursor->pos + 2) % MEM_SIZE;
	}
	else
		cursor->pos = (cursor->pos + 2) % MEM_SIZE;
	//printf ("shift: %d\n", addr % IDX_MOD);
}

static	void	ldi_lldi(t_cursor *cursor, char *mem, int32_t *val, int f)
{
	int32_t	addr;

	mem += mem[19];
	if (cursor->types[1] == T_REG_CODE)
	{
		if (mem[0] > 16 || mem[0] < 1)
			return ;
		val[1] = cursor->reg[mem[0] - 1];
		mem += 1;
	}
	else if (cursor->types[1] == T_IND_CODE)
	{
		memory_read(mem, 0, &val[1], IND_SIZE);
		rev_endian(&val[1], 4);
		mem += 2;		
	}
	else
		return ;
	if (mem[0] > 16 || mem[0] < 1)
		return ;
		addr = f ? addr = (cursor->pos + val[0] + val[1]) : 
		(cursor->pos + val[0] + val[1]) % IDX_MOD;
	cursor->reg[mem[0] - 1] = addr;
}

void			ldi(t_main *main, t_cursor *cursor, char *area)
{
	int32_t	val[3];
	char	mem[20];

	ft_bzero(val, 3 * 4);
	memory_read(area, cursor->pos + 2, mem, 9);
	if (cursor->types[0] == T_REG_CODE)
	{
		if (mem[0] > 16 || mem[0] < 1)
			return ;
		val[0] = cursor->reg[mem[0] - 1];
		mem[19] = 1;
	}
	if (cursor->types[0] == T_DIR_CODE)
	{
		memory_read(mem, 0, &val[0], 2);
		rev_endian(&val[0], 4);
		mem[19] = 2;
	}
	if (cursor->types[0] == T_IND_CODE)
	{
		memory_read(mem, 0, &val[0], IND_SIZE);
		rev_endian(&val[0], 4);
		mem[19] = 2;
	}
	ldi_lldi(cursor, mem, val, 0);
}

void			lldi(t_main *main, t_cursor *cursor, char *area)
{
	int32_t	val[3];
	char	mem[20];

	ft_bzero(val, 3 * 4);
	memory_read(area, cursor->pos + 2, mem, 9);
	if (cursor->types[0] == T_REG_CODE)
	{
		if (mem[0] > 16 || mem[0] < 1)
			return ;
		val[0] = cursor->reg[mem[0] - 1];
		mem[19] = 1;
	}
	if (cursor->types[0] == T_DIR_CODE)
	{
		memory_read(mem, 0, &val[0], 2);
		rev_endian(&val[0], 4);
		mem[19] = 2;
	}
	if (cursor->types[0] == T_IND_CODE)
	{
		memory_read(mem, 0, &val[0], IND_SIZE);
		rev_endian(&val[0], 4);
		mem[19] = 2;
	}
	ldi_lldi(cursor, mem, val, 1);
}

static	void	t_sti(t_cursor *cursor, char *mem, int32_t *val)
{
	mem += mem[19];
	if (cursor->types[2] == T_REG_CODE)
	{
		if (mem[0] > 16 || mem[0] < 1)
			return ;
		val[2] = cursor->reg[mem[0] - 1];
	}
	else if (cursor->types[2] == T_IND_CODE)
	{
		memory_read(mem, 0, &val[2], 2);
		rev_endian(&val[1], 4);
	}
	else
		return ;
	cursor->reg[val[0] - 1] = (cursor->pos +  val[1] + val[2]) % IDX_MOD;
}

void			sti(t_main *main, t_cursor *cursor, char *area)
{
	int32_t	val[3];
	char	mem[20];

	ft_bzero(val, 3 * 4);
	memory_read(area, cursor->pos + 2, mem, 9);
	if (mem[0] > 16 || mem[0] < 1)
		return ;
	val[0] = mem[0];
	if (cursor->types[1] == T_REG_CODE)
	{
		if (mem[1] > 16 || mem[1] < 1)
			return ;
		val[1] = cursor->reg[mem[1] - 1];
		mem[19] = 1 + 1;
	}
	if (cursor->types[1] == T_DIR_CODE)
	{
		memory_read(mem, 1, &val[1], 2);
		rev_endian(&val[1], 4);
		mem[19] = 2 + 1;
	}
	if (cursor->types[1] == T_IND_CODE)
	{
		memory_read(mem, 1, &val[1], IND_SIZE);
		rev_endian(&val[1], 4);
		mem[19] = 2 + 1;
	}
	t_sti(cursor, mem, val);
}
