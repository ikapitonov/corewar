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
	int		tmp;

	reader = main->reader;
	while (reader->i < reader->count)
	{
		reader->j = 0;
		line = reader->arr[reader->i];
		trim_str(line, &reader->j);
		if (line[reader->j] == COMMENT_CHAR ||
			line[reader->j] == ALT_COMMENT_CHAR ||
			!line[reader->j])
			;
		else if (line[reader->j] == '.')
			name_or_comment(main);
		else if ((tmp = int_strchr(line + reader->j)))
			get_token(main, reader, tmp);
		else if ((tmp = is_mark(line + reader->j, reader)))
			get_mark(main, reader, tmp);
		else
			pars_error("Invalid command", reader);
		reader->i += 1;
	}
	analysis(main);
}
