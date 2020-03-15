/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 21:04:13 by bpole             #+#    #+#             */
/*   Updated: 2020/03/15 21:05:40 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		put_pause(t_main *main)
{
	if (main->pause == 0)
		main->pause = 1;
	else
		main->pause = 0;
}

static void		speed_control(int key, t_main *main)
{
	if (key == NUM_PAD_MINUS)
	{
		if (main->speed == 0)
			main->speed = 0;
		else
			main->speed--;
	}
	if (key == NUM_PAD_PLUS)
		main->speed++;
}

int				lem_hook_keydown(int key, t_main *main)
{
	if (key == MAIN_PAD_ESC)
		exit(EXIT_SUCCESS);
	if (key == MAIN_PAD_P)
		put_pause(main);
	if (key == MAIN_PAD_R)
		;
	if (key == MAIN_PAD_SPACE)
		main->one_step = 1;
	if (key == NUM_PAD_MINUS || key == NUM_PAD_PLUS)
		speed_control(key, main);
	render(main);
	return (0);
}
