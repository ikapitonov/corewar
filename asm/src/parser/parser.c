/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:48:40 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/03 17:48:42 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void			parser(t_main *main)
{
	t_read	*reader;
	char	*line;
	int		i;
	int		tmp;

	reader = main->reader;
	while (reader->i < reader->count)
	{
		reader->j = 0;
		i = reader->i;
		line = reader->arr[i];
		trim_str(line, &reader->j);
		if (line[reader->j] == COMMENT_CHAR ||
			line[reader->j] == ALT_COMMENT_CHAR ||
			!line[reader->j])
			;
		else if (line[reader->j] == '.')
			name_or_comment(main);
		else if ((tmp = int_strchr(line + reader->j)))
			token(main, reader, tmp, line + reader->j);
		// else if (is_mark(line, reader->j))
		// 	p();
		reader->i += 1;
	}
}
