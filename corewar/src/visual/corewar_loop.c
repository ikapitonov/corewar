/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 21:06:09 by bpole             #+#    #+#             */
/*   Updated: 2020/03/15 21:11:39 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			count_coursor(t_main *main)
{
	t_cursor	*cursor;
	int			i;

	i = -1;
	while (++i < MEM_SIZE)
		main->cell[i].cursor = 0;
	cursor = main->cursor;
	main->cursors = 0;
	while (cursor)
	{
		main->cursors++;
		main->cell[cursor->pos].cursor = 1;
		cursor = cursor->next;
	}
}

static void		check_finish_game(t_main *main)
{
	if ((!main->cursor || main->cycle_to_die <= 0) && !main->finish)
	{
		if (main->cursor)
			game_exec(main);
		print_winner(main);
		main->finish += 1;
	}
}

int				lem_loop_key_hook(t_main *main)
{
	char		*str;
	static int	i;

	str = "RUN";
	i = main->speed;
	if (main->pause == 1 || main->one_step)
	{
		while ((i-- > 0 || main->one_step) &&
				main->cursor && main->cycle_to_die > 0)
		{
			game_exec(main);
			main->one_step = 0;
		}
		check_finish_game(main);
		count_coursor(main);
		render(main);
	}
	else
		render(main);
	if (main->pause == 0)
		str = "PAUSE";
	mlx_string_put(main->mlx, main->win,
			WIDTH - 350, 50, TEXT_COLOR, str);
	return (0);
}
