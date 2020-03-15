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
	}
	else
		cursor->pos = (cursor->pos + 3) % MEM_SIZE;
}

static int		ldi_lldi(t_cursor *cursor, char *area, char *mem, int f)
{
	int32_t	addr;

	if (cursor->types[1] == T_REG_CODE)
	{
		if (mem[mem[20]] > 16 || mem[mem[20]] < 1)
			return -1;
		((int *)(mem + 12))[0] = cursor->reg[mem[mem[20]] - 1];
		rev_endian(mem + 12, 4);
		mem[11] = mem[mem[20] + 1];
	}
	else if (cursor->types[1] == T_DIR_CODE)
	{
		memory_read(mem + mem[20], 0, mem + 12, IND_SIZE);
		rev_endian(mem + 12, 2);
		((int *)(mem + 12))[0] = *(short *)(mem + 12);
		mem[11] = mem[mem[20] + 2];
	}
	else
		return -1;
	if (mem[11] > 16 || mem[11] < 1)
		return -1;
	if (!f)
		addr = (*(int *)(mem + 12) + *(int *)(mem + 16)) % IDX_MOD;
	else
		addr = (*(int *)(mem + 12) + *(int *)(mem + 16));
	memory_read(area, cursor->pos + addr, &cursor->reg[mem[11] - 1], 4);
	return (cursor->reg[mem[11] - 1] == 0);
}

void			ldi(t_main *main, t_cursor *cursor, char *area)
{
	char	mem[21];

	ft_bzero(mem, 20);
	memory_read(area, cursor->pos + 2, mem, 9);
	if (cursor->types[0] == T_REG_CODE)
	{
		if (mem[0] > 16 || mem[0] < 1)
			return ;
		((int *)(mem + 16))[0] = cursor->reg[mem[0] - 1];
		rev_endian(mem + 16, 4);
		mem[20] = 1;
	}
	if (cursor->types[0] == T_DIR_CODE)
	{
		memory_read(mem, 0, mem + 16, 2);
		rev_endian(mem + 16, 2);
		((int *)(mem + 16))[0] = *(short *)(mem + 16);
		mem[20] = 2;
	}
	if (cursor->types[0] == T_IND_CODE)
	{
		memory_read(mem, 0, mem + 16, IND_SIZE);
		rev_endian(mem + 16, 2);
		memory_read(area, cursor->pos + *(short *)(mem + 16) % IDX_MOD, mem + 16, 4);
		rev_endian(mem + 16, 4);
		mem[20] = 2;
	}
	ldi_lldi(cursor, area, mem, 0);
}

void			lldi(t_main *main, t_cursor *cursor, char *area)
{
	char	mem[21];

	ft_bzero(mem, 20);
	memory_read(area, cursor->pos + 2, mem, 9);
	if (cursor->types[0] == T_REG_CODE)
	{
		if (mem[0] > 16 || mem[0] < 1)
			return ;
		((int *)(mem + 16))[0] = cursor->reg[mem[0] - 1];
		rev_endian(mem + 16, 4);
		mem[20] = 1;
	}
	if (cursor->types[0] == T_DIR_CODE)
	{
		memory_read(mem, 0, mem + 16, 2);
		rev_endian(mem + 16, 2);
		((int *)(mem + 16))[0] = *(short *)(mem + 16);
		mem[20] = 2;
	}
	if (cursor->types[0] == T_IND_CODE)
	{
		memory_read(mem, 0, mem + 16, IND_SIZE);
		rev_endian(mem + 16, 2);
		memory_read(area, cursor->pos + *(short *)(mem + 16) % IDX_MOD, mem + 16, 4);
		rev_endian(mem + 16, 4);
		mem[20] = 2;
	}
	mem[0] = ldi_lldi(cursor, area, mem, 1);
	cursor->carry = mem[0] < 0 ? cursor->carry : mem[0];
}

static void		t_sti(t_main *main, t_cursor *cursor, char *area, char *mem)
{
	int addr;

	if (mem[0] > 16 || mem[0] < 1)
		return ;
	if (cursor->types[2] == T_REG_CODE)
	{
		if (mem[mem[20]] > 16 || mem[mem[20]] < 1)
			return ;
		((int *)(mem + 12))[0] = cursor->reg[mem[mem[20]] - 1];
		rev_endian(mem + 12, 4);
	}
	else if (cursor->types[2] == T_DIR_CODE)
	{
		memory_read(mem, mem[20], mem + 12, 2);
		rev_endian(mem + 12, 2);
		((int *)(mem + 12))[0] = *(short *)(mem + 12);
	}
	else
		return ;
	addr = (*(int *)(mem + 12) + *(int *)(mem + 16)) % IDX_MOD;
	memory_write(main, main->cell[cursor->pos].player,  area, cursor->pos + addr, &cursor->reg[mem[0] - 1], 4);
}

void			sti(t_main *main, t_cursor *cursor, char *area)
{
	char	mem[21];

	ft_bzero(mem, 21);
	memory_read(area, cursor->pos + 2, mem, 9);
	if (cursor->types[1] == T_REG_CODE)
	{
		if (mem[1] > 16 || mem[1] < 1)
			return ;
		((int *)(mem + 16))[0] = cursor->reg[mem[1] - 1];
		rev_endian(mem + 16, 4);
		mem[20] = 1 + 1;
	}
	if (cursor->types[1] == T_DIR_CODE)
	{
		memory_read(mem, 1, mem + 16, 2);
		rev_endian(mem + 16, 2);
		((int *)(mem + 16))[0] = *(short *)(mem + 16);
		mem[20] = 2 + 1;
	}
	if (cursor->types[1] == T_IND_CODE)
	{
		memory_read(mem, 1, mem + 16, IND_SIZE);
		rev_endian(mem + 16, 2);
		memory_read(area, cursor->pos + *(short *)(mem + 16) % IDX_MOD, mem + 16, 4);
		rev_endian(mem + 16, 4);
		mem[20] = 2 + 1;
	}
	t_sti(main, cursor, area, mem);
}
