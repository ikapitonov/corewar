/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 22:20:54 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/06 22:20:55 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static	void	check_names(t_main *main)
{
	t_mark	*mark;
	t_mark	*tmp;

	mark = main->mark;
	while (mark)
	{
		tmp = main->mark;
		while (tmp)
		{
			if (tmp != mark && !ft_strcmp(tmp->name, mark->name))
			{
				die(ft_strjoin("Duplicate names error: ", tmp->name));
			}
			tmp = tmp->next;
		}
		mark = mark->next;
	}
}

void			valid_endline(t_read *reader)
{
	char	*line; 
	char	c;

	line = reader->arr[reader->i];
	while (line[reader->j])
	{
		c = line[reader->j];
		if (!is_empty(c) && c != COMMENT_CHAR && c != ALT_COMMENT_CHAR)
		{
			pars_error("Invalid endline", reader);
		}
		if (c == COMMENT_CHAR || c == ALT_COMMENT_CHAR)
		{
			return ;
		}
		reader->j += 1;
	}
}

void			analysis(t_main *main)
{
	if (!main->name)
		die("Not found Champion name");
	if (!main->comment)
		die("Not found Champion comment");
	if (!main->token)
		die("Error: this program have not instructions");
	check_names(main);
}
