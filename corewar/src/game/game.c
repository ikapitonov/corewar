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
	// СЮДА ВСЕГДА ПРИДЕТ ПРАВИЛЬНЫЙ КОД ОПЕРАЦИИ (1 - 16)
	// вызов функций ассембли  и мы ЗДЕСЬ ДВИГАЕМ ПОЗИЦИЮ КАРЕТКИ
	// cursor->pos должен сдвинуться
	main->move = 0;
	if (cursor->operation_code > 0 && cursor->operation_code < 17)
		op_arr[cursor->operation_code - 1](main, cursor, main->area);
	cursor->pos = (cursor->pos + 1 + main->move) % MEM_SIZE;
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
		if (is_invalid_move(main, cursor, tmp))
			return ;
		if (tmp != cursor->operation_code)
		{
			cursor->operation_code = 0;
			cursor->pos = (cursor->pos + 1) % MEM_SIZE;
			return ;
		}
		asm_functions(main, cursor);
		return ;
	}
	if (is_invalid_move(main, cursor, tmp))
		return ;
	cursor->operation_code = tmp;
	cursor->cycles_to_wait = g_instr[tmp - 1].cost;
	return (cursor_exec(main, cursor));
}

static	void	validate_cursors(t_main *main)
{
	t_cursor	*cursor;
	t_cursor	*tmp;

	cursor = main->cursor;
	if (cursor && cursor->last_live_cycle +
					main->cycle_to_die <= main->cycles_count
				&& cursor->last_live_cycle)
	{
		tmp = cursor;
		main->cursor = main->cursor->next;
		free(tmp);
		cursor = main->cursor;
	}
	while (cursor)
	{
		if (cursor->next && cursor->next->last_live_cycle +
							main->cycle_to_die <= main->cycles_count
						&& cursor->next->last_live_cycle)
		{
			tmp = cursor->next;
			cursor->next = cursor->next->next;
			free(tmp);
		}
		cursor = cursor->next;
	}
}

static	void	set_next_validate(t_main *main)
{
	main->current_cycle_to_die = main->cycles_count + main->cycle_to_die;
}

static	void	validate_update(t_main *main)
{
	main->valids_count = 0;
	main->cycle_to_die -= CYCLE_DELTA;
	set_next_validate(main);
}

static	void	validate_exec(t_main *main)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	validate_cursors(main);
	while (i < main->players)
	{
		count += main->player[i].current_lives;
		main->player[i].current_lives = 0;
		++i;
	}
	if (count < NBR_LIVE)
	{
		main->valids_count += 1;
		if (main->valids_count == MAX_CHECKS)
			validate_update(main);
		else
			set_next_validate(main);
		return ;
	}
	validate_update(main);
}

void			game_exec(t_main *main)
{
	t_cursor	*cursor;

	cursor = main->cursor;
	while (cursor)
	{
		cursor_exec(main, cursor);
		cursor = cursor->next;
	}
	main->cycles_count += 1;
	if (main->current_cycle_to_die == main->cycles_count)
	{
		validate_exec(main);
	//	printf("%d %d %d\n", main->cycles_count, main->current_cycle_to_die, main->cycle_to_die);
	}
}
