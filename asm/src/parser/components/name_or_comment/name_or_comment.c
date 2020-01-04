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

static	void	double_error(int flag, int j, int i)
{
	char	*str;

	str = " COMMAND_NAME \".name\"";
	if (flag)
		str = " COMMAND_NAME \".comment\"";
	error_position("Invalid instruction at token [TOKEN]", str, j, i);	
}

static	void	parse_string(t_main *main, t_read *reader, int flag)
{
	char	*line;
	char	*str;

	line = reader->arr[reader->i];
	trim_str(line, &reader->j);
	if (line[reader->j] != '"')
	{
		if (line[reader->j] != 0)
			error_position("Lexical error at ", "", reader->i, reader->j);
		error_position("Syntax error at token [TOKEN]", " ENDLINE", reader->i, reader->j);
	}
	reader->j += 1;
	str = full_string(main, reader, flag ? COMMENT_LENGTH : PROG_NAME_LENGTH, flag);
	if (flag)
		main->comment = str;
	else
		main->name = str;
	// валидация в конце строки
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
			double_error(0, reader->i, reader->j);
		reader->j += len;
		return (parse_string(main, reader, 0));
	}
	len = (int) ft_strlen(COMMENT_CMD_STRING);
	if (ft_strnequ(line, COMMENT_CMD_STRING, len))
	{
		if (main->comment)
			double_error(1, reader->i, reader->j);
		reader->j += len;
		return (parse_string(main, reader, 1));
	}
	error_position("Lexical error at ", "", reader->i, reader->j);
}
