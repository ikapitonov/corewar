/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 21:14:52 by sjamie            #+#    #+#             */
/*   Updated: 2020/03/15 21:14:53 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void			validate_cursors(t_main *main)
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

void			set_next_validate(t_main *main)
{
	main->current_cycle_to_die = main->cycles_count + main->cycle_to_die;
}

void			validate_update(t_main *main)
{
	main->valids_count = 0;
	main->cycle_to_die -= CYCLE_DELTA;
	set_next_validate(main);
}

void			validate_exec(t_main *main)
{
	int		count;
	int		i;

	i = 0;
	count = main->lives_count;
	main->lives_count = 0;
	validate_cursors(main);
	while (i < main->players)
	{
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

int				is_rm_cursor(t_main *main, t_cursor *cursor)
{
	return (cursor && cursor->last_live_cycle +
					main->cycle_to_die <= main->cycles_count);
}
