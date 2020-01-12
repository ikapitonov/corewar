/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:05:53 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/11 16:05:55 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static	void	push_stack(t_main *main, int *stack)
{
	int		tmp;
	int		i;

	i = 0;
	while (i < MAX_PLAYERS + 1)
	{	
		stack[i] = -1;
		++i;
	}
	i = 0;
	while (i < MAX_PLAYERS)
	{
		tmp = main->player[i].id;
		if (tmp)
			stack[tmp] = i;
		if (tmp > main->players)
			help();
		++i;
	}
}

static	int		get_id(int *stack, int index)
{
	int		i;

	i = 1;
	while (i < MAX_PLAYERS + 1)
	{
		if (stack[i] == -1)
		{
			stack[i] = index;
			return (i);
		}
		++i;
	}
	die("get_id");
	return (0);
}

void			calc_ids(t_main *main)
{
	int		stack[MAX_PLAYERS + 1];
	int		i;

	push_stack(main, stack);
	i = 0;
	while (i < main->players)
	{
		if (!main->player[i].id)
		{
			main->player[i].id = get_id(stack, i);
		}
		++i;
	}
}

static	void	check_double(t_main *main, int n)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS - 1)
	{
		if (main->player[i].id == n)
		{
			help();
		}
		++i;
	}
}

void			init_player(t_main *main, int ch, int n)
{
	t_read	content;

	file_get_content(&content, ch);
	if (!content.str)
		die("Empty file");
	valid_file_size(content.str, (int) content.size);
	check_file_content(main, &content);
	main->player[main->players].content = content.str;
	main->player[main->players].file_size = (int) content.size;
	main->player[main->players].code_size = (int) content.size -
		(PROG_NAME_LENGTH + COMMENT_LENGTH + HEADER_VAR);
	if (n)
		check_double(main, n);
	main->player[main->players].id = n;
}
