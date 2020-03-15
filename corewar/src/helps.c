/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 21:01:26 by sjamie            #+#    #+#             */
/*   Updated: 2020/03/15 21:01:28 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void			print_winner(t_main *main)
{
	int		winner;
	int		i;

	winner = main->players;
	i = main->players;
	while (i)
	{
		if (main->player[main->p_index[i]].all_lives >
			main->player[main->p_index[winner]].all_lives)
			winner = i;
		i--;
	}
	ft_printf("Contestant %d, \"%s\", has won !\n", winner,
			main->player[main->p_index[winner]].name);
}

void			die(const char *reason)
{
	int		fd;

	fd = 1;
	if (reason && reason[0])
		write(fd, reason, ft_strlen(reason));
	write(fd, "\n", 1);
	exit(1);
}
