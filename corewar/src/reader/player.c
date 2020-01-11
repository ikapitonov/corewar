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
	// int		i;

	// i = 1;
	// while (i < MAX_PLAYERS)
	// {
	// 	stack[main->player[main->players].id]
	// 	++i;
	// }
	return ;
}

void			calc_ids(t_main *main)
{
	int		stack[MAX_PLAYERS + 1];

	if (main->)
}

static	void	check_double(t_main *main, int n)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS - 1)
	{
		if (main->player[i].id == n)
			help();
		++i;
	}
}

void			init_player(t_main *main, int ch, int n)
{
	t_read	content;

	file_get_content(&content, ch);
	valid_file_size(content.str, (int) content.size);
	main->player[main->players].content = content.str;
	main->player[main->players].file_size = (int) content.size;
	main->player[main->players].code_size = (int) content.size -
		(PROG_NAME_LENGTH + COMMENT_LENGTH + HEADER_VAR);
	if (n)
		check_double(main, n);
	main->player[main->players].id = n;
}
