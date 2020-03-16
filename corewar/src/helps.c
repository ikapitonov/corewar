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

	winner = main->players - 1;
	i = main->players - 1;
	while (i--)
	{
		if (main->player[i].all_lives >
			main->player[winner].all_lives)
			winner = i;
	}
	main->winner = winner;
	ft_printf("Contestant %d, \"%s\", has won !\n", winner + 1,
			main->player[winner].name);
}

void			sort_p_index(t_main *main)
{
	t_player	tmp;
	int			i;
	int			j;

	i = 0;
	while (i < main->players)
	{
		j = 0;
		while (j < main->players - 1)
		{
			if (main->player[j].id > main->player[j + 1].id)
			{
				tmp = main->player[j + 1];
				main->player[j + 1] = main->player[j];
				main->player[j] = tmp;
			}
			++j;
		}
		++i;
	}
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
