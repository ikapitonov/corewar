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

	len = get_arg_types(cursor->operation_code - 1, cursor->types, main->area, cursor->pos);
	ft_printf ("%d\n", cursor->operation_code);
	//ft_printf("check: %d\n", check_arg_types(cursor->types, cursor->operation_code - 1));

	if (!check_arg_types(cursor->types, cursor->operation_code - 1))
		op_arr[cursor->operation_code - 1](main, cursor, main->area);
	if (!len)
		++len;
	if (cursor->operation_code != 9)	
		cursor->pos = (cursor->pos + len) % MEM_SIZE;
	cursor->operation_code = 0;
	//printf ("ss\n");
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

static	int		is_rm_cursor(t_main *main, t_cursor *cursor)
{
	return (cursor && cursor->last_live_cycle +
					main->cycle_to_die <= main->cycles_count
				/*&& cursor->last_live_cycle*/);
}

static	void	validate_cursors(t_main *main)
{
	t_cursor	*cursor;
	t_cursor	*prev;

	cursor = main->cursor;
	while (is_rm_cursor(main, cursor))
	{
		main->cursor = cursor->next;
		free(cursor);
		cursor = main->cursor;
	}
	cursor = main->cursor;
	prev = cursor;
	while (cursor)
	{
		if (is_rm_cursor(main, cursor))
		{
			prev->next = cursor->next;
			free(cursor);
			cursor = prev;
		}
		prev = cursor;
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
		p();
		validate_exec(main);
		printf("%d %d %d\n", main->cycles_count, main->current_cycle_to_die, main->cycle_to_die);
	}
}