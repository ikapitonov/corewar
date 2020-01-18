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

void	zjmp(t_main *main, t_cursor *cursor, char *area)
{
	uint16_t	addr;
	
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

void	ldi(t_main *main, t_cursor *cursor, char *area)
{
	(void)main;
	(void)cursor;
	(void)area;
}

void	sti(t_main *main, t_cursor *cursor, char *area)
{
	(void)main;
	(void)cursor;
	(void)area;
}

void	lldi(t_main *main, t_cursor *cursor, char *area)
{
	(void)main;
	(void)cursor;
	(void)area;
}
