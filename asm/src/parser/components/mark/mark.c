/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:29:46 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/05 19:29:48 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/asm.h"

static	int		needle_token(t_read *reader, int start)
{
	char	*line;

	line = reader->arr[reader->i];
	while (is_empty(line[reader->j]))
		reader->j += 1;
	if (is_comment(line[reader->j]) && (reader->i += 1))
		return (needle_token(reader, start));
	if (!line[reader->j])
	{
		reader->j = 0;
		reader->i += 1;
		if (reader->i == reader->count)
		{
			reader->i -= 1;
			if (!(start == reader->i))
				return (1);
			pars_error("Not found new line (rule)", reader);
		}
		return (needle_token(reader, start));
	}
	return (ligth_is_mark(reader->arr[reader->i] + reader->j) ? 2 : 0);
}

static	void	*new_mark(t_main *main, char *line, int len)
{
	t_mark	*mark;
	char	*str;

	mark = (t_mark*)smart_malloc(sizeof(t_mark));
	str = (char*)smart_malloc((len + 1) * sizeof(char));
	ft_strncpy(str, line, len);
	str[len] = 0;
	mark->name = str;
	mark->token = NULL;
	mark->mark = NULL;
	mark->next = NULL;
	if (main->mark_flag)
	{
		main->last_mark->mark = mark;
		main->mark_flag = 0;
	}
	if (main->last_mark)
	{
		main->last_mark->next = mark;
		main->last_mark = mark;
		return ((void*)mark);
	}
	main->mark = mark;
	main->last_mark = mark;
	return ((void*)mark);
}

void			get_mark(t_main *main, t_read *reader, int tmp)
{
	t_mark	*mark;
	char	*line;
	int		res;

	if (!main->name || !main->comment)
		pars_error("Undefined Champion name or comment", reader);
	mark = (t_mark*)new_mark(main, reader->arr[reader->i] + reader->j, tmp);
	reader->j += tmp + 1;
	if ((res = needle_token(reader, reader->i)) == 1)
		return ;
	else if (res == 2)
	{
		main->mark_flag = 1;
		reader->i -= 1;
		return ;
	}
	line = reader->arr[reader->i];
	if (!(res = int_strchr(line + reader->j)))
	{
		pars_error("Invalid instruction after label", reader);
	}
	get_token(main, reader, res);
	mark->token = main->last_token;
}
