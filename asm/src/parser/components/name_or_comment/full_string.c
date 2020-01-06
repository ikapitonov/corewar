/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:38:38 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/04 18:38:39 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/asm.h"

static	void	check_max_index(int i, int flag, int length, t_read *reader)
{
	char	*str;

	if (i < length)
		return ;
	if (flag)
		str = "Champion comment ";
	else
		str = "Champion name ";
	pars_error(ft_strjoin(str, ft_strjoin("too long: Max length ",
				ft_itoa(length))), reader);
}

static	void	next_line(t_read *reader, int *i, char *str)
{
	reader->i += 1;
	if (reader->i == reader->count)
	{
		reader->i -= 1;
		pars_error("Invalid string", reader);
	}	
	str[*i] = '\n';
	*i += 1;
	reader->j = 0;
}

char			*full_string(t_main *main, t_read *reader,
							int length, int flag)
{
	char	str[length + 1];
	char	*line;
	int		i;

	i = 0;
	while (reader->arr[reader->i][reader->j] != '"')
	{
		line = reader->arr[reader->i];
		if (!line[reader->j])
		{
			next_line(reader, &i, str);
			continue ;
		}
		check_max_index(i, flag, length, reader);
		str[i] = line[reader->j];
		i += 1;
		reader->j += 1;
	}
	str[i] = 0;
	reader->j += 1;
	return (ft_strdup(str));
}
