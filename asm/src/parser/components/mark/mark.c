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

static	void	needle_token(t_read *reader)
{
	char	*line;

	line = reader->arr[reader->i];
	while (is_empty(line[reader->j]))
	{
		reader->j += 1;
	}
	if (!line[reader->j])
	{
		reader->j = 0;
		reader->i += 1;
		if (reader->i == reader->count)
			die("End >needle_token");
		return (needle_token(reader));
	}
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
	mark->next = NULL;
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

	mark = (t_mark*)new_mark(main, reader->arr[reader->i] + reader->j, tmp);
	reader->j += tmp + 1;
	needle_token(reader);
	line = reader->arr[reader->i];
	if (!(res = int_strchr(line + reader->j)))
	{
		die("Error > get_mark");
	}
	get_token(main, reader, res);
	mark->token = main->last_token;
}
