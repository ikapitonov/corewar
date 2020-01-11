/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:22:47 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/11 15:22:49 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void			help(void)
{
	die("Here help");
}

static	void	insert_player(t_main *main, char *player, int n)
{
	int		ch;

	if (main->players >= MAX_PLAYERS)
		help();
	valid_filename(player);
	if ((ch = open(player, O_RDONLY)) == -1)
	{
		die(ft_sprintf("Can't read source file %s", player));
	}
	init_player(main, ch, n);
	if (close(ch) == -1)
	{
		die(ft_sprintf("Can't close source file  %s", player));
	}
	main->players += 1;
}

static	void	insert_flag(t_main *main, int count_args,
							char *params[], int i)
{
	int		res;

	if (!ft_strncmp(params[i] + 1, DUMP, DUMP_LEN) && !params[i][5]
		&& is_number(count_args, params, i) && !main->dump)
	{
		main->dump = valid_number(params[i + 1]);
	}
	else if (*(params[i] + 1) == 'n' && !params[i][2]
		&& is_number(count_args, params, i) && i + 2 < count_args)
	{
		if ((res = valid_number(params[i + 1])) > MAX_PLAYERS)
			help();
		insert_player(main, params[i + 2], res);
	}
	else
		help();
}

static	void	analysis(t_main *main)
{
	if (MIN_PLAYERS < main->players)
		help();
	calc_ids(main);
}

void			insert_params(t_main *main, int count_args, char *params[])
{
	int		i;

	if (count_args < 3)
		help();
	i = 1;
	while (i < count_args)
	{
		if (params[i][0] == '-')
		{
			insert_flag(main, count_args, params, i);
			i += params[i][1] == 'n' ? 2 : 1;
		}
		else
		{
			insert_player(main, params[i], 0);
		}
		++i;
	}
	analysis(main);
}
