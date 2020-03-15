/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 17:47:36 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/17 22:31:36 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static	void	asm_functions(t_main *main, t_cursor *cursor)
{
	int		len;

	len = get_arg_types(cursor->operation_code - 1,
						cursor->types, main->area, cursor->pos);
	if (!check_arg_types(cursor->types, cursor->operation_code - 1))
		g_op_arr[cursor->operation_code - 1](main, cursor, main->area);
	if (!len)
		++len;
	if (cursor->operation_code != 9)
		cursor->pos = (cursor->pos + len) % MEM_SIZE;
	cursor->operation_code = 0;
}

static	int		is_invalid_move(t_main *main, t_cursor *cursor, int32_t tmp)
{
	if (tmp < 1 || tmp > COUNT_TOKENS)
	{
		cursor->operation_code = 0;
		cursor->pos = (cursor->pos + 1) % MEM_SIZE;
		return (1);
	}
	return (0);
}

static	void	cursor_exec(t_main *main, t_cursor *cursor)
{
	int32_t	tmp;

	if (cursor->cycles_to_wait && --cursor->cycles_to_wait)
		return ;
	tmp = memory_read_rev_endian(main->area, cursor->pos, 1);
	if (cursor->operation_code)
	{
		if (is_invalid_move(main, cursor, cursor->operation_code))
			return ;
		asm_functions(main, cursor);
		return ;
	}
	if (is_invalid_move(main, cursor, tmp))
		return ;
	cursor->operation_code = tmp;
	cursor->cycles_to_wait = g_instr[tmp - 1].cost;
	return (cursor_exec(main, cursor));
}

void			game_exec(t_main *main)
{
	t_cursor	*cursor;

	main->cycles_count += 1;
	cursor = main->cursor;
	while (cursor)
	{
		cursor_exec(main, cursor);
		cursor = cursor->next;
	}
	if (main->current_cycle_to_die == main->cycles_count)
	{
		validate_exec(main);
	}
}
