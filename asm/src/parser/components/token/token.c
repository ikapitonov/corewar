/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:54:04 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/04 19:54:06 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/asm.h"

static	int		is_token(char *line, int position)
{
	int     i;

    i = 0;
    while (i < COUNT_TOKENS)
    {
        if (ft_strnequ(line, g_instr[i].name, position))
        {
            return (i);
        }
        ++i;
    }
    return (-1);
}

static	int		help_func(int c)
{
	return (c != SEPARATOR_CHAR && c != COMMENT_CHAR &&
			c != ALT_COMMENT_CHAR && c && !is_empty(c) ? 1 : 0);
}

static	void	clean_after_arg(t_read *reader, char *line)
{
	while (help_func(line[reader->j]))
		reader->j += 1;
	if (line[reader->j] == SEPARATOR_CHAR)
		reader->j += 1;
}

static  void    token_info(t_main *main, t_read *reader, char *line, int index)
{
	int		arr[3];
    int     i;

	i = 0;
	while (i < g_instr[index].count_args)
	{
		printf("%s\n", line);
        trim_str(line, &reader->j);
        line += reader->j;
        if (*line == 'r')
            p();
        else if (ft_isdigit(*line))
            p();
        else if ((*line == '+' || *line == '-') && ft_isdigit(line[1]))
            p();
        else if (*line == DIRECT_CHAR)
            p();
        else
            die("Invalid token");
		clean_after_arg(reader, line);
        ++i;
	}
}

void			token(t_main *main, t_read *reader, int tmp, char *line)
{
	t_token	*token;
    int     index;

    if ((index = is_token(line, tmp)) == -1)
        return ;
	token = new_token(index);
    reader->j += tmp;
    token_info(main, reader, line, index);
}