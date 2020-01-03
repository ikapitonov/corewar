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

void			parser(t_main *main, char **str, int ch)
{
	t_pars	parsing;
	char	*line;
	int		i;

	line = *str;
	main->lines += 1;
	parsing.main = main;
	parsing.ch = ch;
	parsing.line = str;
	i = 0;
	while (line[i])
	{
		trim_str(line, &i);
		if (line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT_CHAR || !line[i])
			return ;
		if (line[i] == '.')
			return (name_or_comment(&parsing, i));
		i += 1;
	}
}
