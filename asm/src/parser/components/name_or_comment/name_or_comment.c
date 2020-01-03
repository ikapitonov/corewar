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

static	void	get_string(t_pars *pars, int *i, int len, int flag)
{
	char	new[len + 1];
	int		j;

	j = 0;
	// if (!full_string(new, pars, *i, len))
	// {
	// 	error_position("Syntax error at token [TOKEN]", " END \"(null)\"",
	// 					pars->main->lines, *i);
	// }
	// if (flag)
	// 	pars->main->comment = ft_strdup(str);
	// else
	// 	pars->main->name = ft_strdup(str);
}

static	void	parse_string(int flag, t_pars *pars, int i)
{
	char	*line;

	line = *pars->line;
	trim_str(line, &i);
	if (*(line + i) != '"')
	{
		if (*(line + i) != 0)
			error_position("Lexical error at ", "", pars->main->lines, i);
		error_position("Syntax error at token [TOKEN]", " ENDLINE", pars->main->lines, i);
	}
	i += 1;
	get_string(pars, &i, !flag ? PROG_NAME_LENGTH : COMMENT_LENGTH, flag);
}

void			name_or_comment(t_pars *pars, int i)
{
	char	*line;
	int		len;

	line = *pars->line;
	len = (int) ft_strlen(NAME_CMD_STRING);
	if (ft_strnequ(line + i, NAME_CMD_STRING, len))
	{
		if (pars->main->name)
			double_error(0, pars->main->lines, i);
		return (parse_string(0, pars, i + len));
	}
	len = (int) ft_strlen(COMMENT_CMD_STRING);
	if (ft_strnequ(line + i, COMMENT_CMD_STRING, len))
	{
		if (pars->main->comment)
			double_error(1, pars->main->lines, i);
		return (parse_string(1, pars, i + len));
	}
	error_position("Lexical error at ", "", pars->main->lines, i);
}
