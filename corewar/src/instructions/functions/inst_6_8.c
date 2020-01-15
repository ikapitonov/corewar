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

// void	and_reg(t_cursor *cursor, char *area, char *mem)
// { 
// 	if (cursor->types[1] == T_REG_CODE)
// 		{
// 			if (mem[1] > 16 || mem[2] > 16 || !mem[1] || !mem[2])
// 				return ;
// 			cursor->reg[mem[2] - 1] = 
// 			cursor->reg[mem[0] - 1] & cursor->reg[mem[1] - 1];
// 			cursor->carry = !cursor->reg[mem[1] - 1];
// 			return;
// 		}
// 		if (cursor->types[1] == T_DIR_CODE)
// 		{
// 			if (mem[4] > 16 || !mem[4])
// 				return;
// 			cursor->reg[mem[5] - 1] = *(int *)(mem + 1) &
// 			cursor->reg[mem[0] - 1];
// 			cursor->carry = !cursor->reg[mem[5] - 1];
// 			return;
// 		}
// 		if (mem[3] > 16 || !mem[3])
// 			return;
// 		memory_read(area, cursor->pos + *(short *)(mem + 1) / IDX_MOD,
// 		mem + 4, 4);
// 		cursor->reg[mem[3] - 1] = *(int *)(mem + 4) &
// 		cursor->reg[mem[0] - 1];
// 		cursor->carry = !cursor->reg[mem[3] - 1];
// }

// void	and_dir(t_cursor *cursor, char *area, char *mem)
// {
// 	if (cursor->types[1] == T_REG_CODE)
// 		{
// 			if (mem[1] > 16 || mem[2] > 16 || !mem[1] || !mem[2])
// 				return ;
// 			cursor->reg[mem[2] - 1] = 
// 			cursor->reg[mem[0] - 1] & cursor->reg[mem[1] - 1];
// 			cursor->carry = !cursor->reg[mem[1] - 1];
// 			return;
// 		}
// 		if (cursor->types[1] == T_DIR_CODE)
// 		{
// 			if (mem[4] > 16 || !mem[4])
// 				return;
// 			cursor->reg[mem[5] - 1] = *(int *)(mem + 1) &
// 			cursor->reg[mem[0] - 1];
// 			cursor->carry = !cursor->reg[mem[5] - 1];
// 			return;
// 		}
// 		if (mem[3] > 16 || !mem[3])
// 			return;
// 		memory_read(area, cursor->pos + *(short *)(mem + 1) / IDX_MOD,
// 		mem + 4, 4);
// 		cursor->reg[mem[3] - 1] = *(int *)(mem + 4) &
// 		cursor->reg[mem[0] - 1];
// 		cursor->carry = !cursor->reg[mem[3] - 1];
// }

void    and(t_main *main, t_cursor *cursor, char *area)
{
	char	mem[9];

	memory_read(area, cursor->pos + 2, mem, 9);
	if (cursor->types[0] == T_REG_CODE)
	{
		// if (mem[0] > 16 || !mem[0])
		// 	return ;
		// and_reg(cursor, area, mem);
	}
	if (cursor->types[0] == T_DIR_CODE)
	{

	}
	if (cursor->types[0] == T_IND_CODE)
	{
		
	}
}

void    or(t_main *main, t_cursor *cursor, char *area)
{}

void    xor(t_main *main, t_cursor *cursor, char *area)
{}