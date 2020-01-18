/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_13_16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:41:50 by matruman          #+#    #+#             */
/*   Updated: 2020/01/17 22:31:36 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lld(t_main *main, t_cursor *cursor, char *area)
{
	uint8_t		regnum;
	int16_t		addr;
	
	(void)main;
	if (cursor->types[0] == T_DIR_CODE)
	{
		memory_read(area, cursor->pos + 6, &regnum, 1);
		if (!regnum || regnum > 16)
			return ;
		memory_read(area, cursor->pos + 2, &cursor->reg[regnum - 1], 4);
		cursor->carry = !cursor->reg[regnum - 1];
		return ;
	}
	memory_read(area, cursor->pos + 2, &addr, 2);
	rev_endian(&addr, 2);
	memory_read(area, cursor->pos + 4, &regnum, 1);
	if (!regnum || regnum > 16)
		return ;
	memory_read(area, addr - cursor->pos,
				&cursor->reg[regnum - 1], 4);
	cursor->carry = !cursor->reg[regnum - 1];
}

void			cursor_copy_and_add(t_main *main, t_cursor *current, t_cursor *cursor, int16_t addr)
{
	int			i;
	
	i = -1;
	while (++i < REG_NUMBER)
		cursor->reg[i] = current->reg[i];
	cursor->pos = addr;
	cursor->command = current->command;
	cursor->cycles = current->cycles;
	i = -1;
	while (++i < 3)
		cursor->types[i] = current->types[i];
	cursor->carry = current->carry;
	cursor->next = main->cursor;
	main->cursor = cursor;
}

void	op_fork(t_main *main, t_cursor *cursor, char *area)
{
	t_cursor	*new;
	int16_t		addr;
	
	ft_printf("1\n");
	memory_read(area, cursor->pos + 2, &addr, 2);
	rev_endian(&addr, 2);
	new = (t_cursor*)smart_malloc(sizeof(t_cursor));
	cursor_copy_and_add(main, cursor, new, addr % IDX_MOD);
	ft_printf("2\n");
	main->move = 2;
}

void	lfork(t_main *main, t_cursor *cursor, char *area)
{
	t_cursor	*new;
	int16_t		addr;
	
	memory_read(area, cursor->pos + 2, &addr, 2);
	rev_endian(&addr, 2);
	new = (t_cursor*)smart_malloc(sizeof(t_cursor));
	cursor_copy_and_add(main, cursor, new, cursor->pos + addr);
}

void	aff(t_main *main, t_cursor *cursor, char *area)
{
	int32_t	val;
	
	if (main->flag_a)
	{
		memory_read(area, cursor->pos + 2, &val, 4);
		rev_endian(&val, 4);
		write(1, &val, 1);
	}
}