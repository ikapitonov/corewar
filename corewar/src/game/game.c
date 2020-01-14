/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 17:47:36 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/12 17:47:37 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static	void	asm_functions(t_main *main, t_cursor *cursor)
{
	// СЮДА ВСЕГДА ПРИДЕТ ПРАВИЛЬНЫЙ КОД ОПЕРАЦИИ (1 - 16)
	// вызов функций ассембли  и мы ЗДЕСЬ ДВИГАЕМ ПОЗИЦИЮ КАРЕТКИ
	// cursor->pos должен сдвинуться 
	return ;
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
	tmp = memory_read_rev_endian(main->area, cursor->pos, 4);
	if (cursor->operation_code)
	{
		if (is_invalid_move(main, cursor, tmp))
			return ;
		asm_functions(main, cursor);
		return ;
	}
	if (is_invalid_move(main, cursor, tmp))
		return ;
	cursor->operation_code = tmp;
	cursor->cycles_to_wait = g_instr[tmp - 1].cost;
	return (cursor_exec(main, cursor));// именно так vrode - checknyt'
}

static	void	kill_cursor(t_cursor *here, t_cursor *del)
{
	here->next = here->next->next;
	free(del);
}

static	void	validate_cursors(t_main *main)
{
	t_cursor	*cursor;
	t_cursor	*tmp;

	cursor = main->cursor;
	if (cursor && cursor->next->last_live_cycle +
					main->cycle_to_die <= main->cycles_count)
	{
		tmp = cursor;
		main->cursor = main->cursor->next;
		free(tmp);
		cursor = main->cursor;
	}
	while (cursor)
	{
		if (cursor->next && cursor->next->last_live_cycle +
							main->cycle_to_die <= main->cycles_count)
		{
			tmp = cursor->next;
			cursor->next = cursor->next->next;
			free(tmp);
		}
		cursor = cursor->next;
	}
}

static	void	validate_update(t_main *main)
{
	main->valids_count = 0;
	main->cycle_to_die -= CYCLE_DELTA;
	main->current_cycle_to_die = main->cycles_count + main->cycle_to_die;
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
		validate_exec(main);
}
