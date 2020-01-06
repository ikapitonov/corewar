/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_or_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:20:13 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/03 20:20:15 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/asm.h"

static	void	double_error(int flag, t_read *reader)
{
	char	*str;

	if (flag)
		str = "\".comment\"";
	else
		str = "\".name\"";
	pars_error(ft_strjoin(str, " already been announced"), reader);
}

static	void	parse_string(t_main *main, t_read *reader, int flag)
{
	char	*line;
	char	*str;

	line = reader->arr[reader->i];
	trim_str(line, &reader->j);
	if (line[reader->j] != '"')
		pars_error("Invalid command name", reader);
	reader->j += 1;
	str = full_string(main, reader, flag ? COMMENT_LENGTH
										: PROG_NAME_LENGTH, flag);
	if (flag)
		main->comment = str;
	else
		main->name = str;
	valid_endline(reader);
}

void			name_or_comment(t_main *main)
{
	t_read	*reader;
	char	*line;
	int		len;

	reader = main->reader;
	line = reader->arr[reader->i] + reader->j;
	len = (int) ft_strlen(NAME_CMD_STRING);
	if (ft_strnequ(line, NAME_CMD_STRING, len))
	{
		if (main->name)
			double_error(0, reader);
		reader->j += len;
		return (parse_string(main, reader, 0));
	}
	len = (int) ft_strlen(COMMENT_CMD_STRING);
	if (ft_strnequ(line, COMMENT_CMD_STRING, len))
	{
		if (main->comment)
			double_error(1, reader);
		reader->j += len;
		return (parse_string(main, reader, 1));
	}
	pars_error("Invalid command", reader);
}
