/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_1_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:40:34 by matruman          #+#    #+#             */
/*   Updated: 2020/01/11 17:40:36 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    live(t_main *main, t_cursor *cursor, char *area)
{
	int	val;

	memory_read(area, cursor->pos + 1, &val, 4);
	rev_endian(&val, 4);
	if (-val <= main->players)
		main->player[-val].current_lives++;
}

void	ld(t_main *main, t_cursor *cursor, char *area)
{
	uint8_t		regnum;
	uint16_t	addr;

	if (cursor->types[0] == T_DIR_CODE)
	{
		memory_read(area, cursor->pos + 6, &regnum, 1);
		if (regnum > 16)
			return ;
		memory_read(area, cursor->pos + 2, &cursor->registers[regnum - 1], 4);
		return ;
	}
	memory_read(area, cursor->pos + 2, &addr, 2);
	rev_endian(&addr, 2);
	memory_read(area, cursor->pos + 4, &regnum, 1);
	memory_read(area, cursor->pos + addr % IDX_MOD,
	&cursor->registers[regnum - 1], 4);
}

void	st(t_main *main, t_cursor *cursor, char *area)
{
	uint8_t		regnum1;
	uint8_t		regnum2;
	uint16_t	addr;

	memory_read(area, cursor->pos + 2, &regnum1, 1);
	if (cursor->types[2] == T_REG_CODE)
	{
		memory_read(area, cursor->pos + 3, &regnum2, 1);
		if (regnum1 > 16 || regnum2 > 16)
			return ;
		cursor->registers[regnum2 - 1] = cursor->registers[regnum1 - 1];
		return ;
	}
	memory_read(area, cursor->pos + 3, &addr, 2);
	rev_endian(&addr, 2);
	memory_write(area, cursor->pos + addr % IDX_MOD,
	&cursor->registers[regnum1 - 1], 2);
}