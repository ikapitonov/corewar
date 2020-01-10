/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 21:24:06 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/10 21:24:08 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/asm.h"

static	int		label_len(t_read *reader)
{
	char	*line;
	int		i;

	i = 0;
	line = reader->arr[reader->i];
	while (line[reader->j])
	{
		if (!ft_strchr(LABEL_CHARS, line[reader->j]))
		{
			if (args_exception(line[reader->j]))
				pars_error("Invalid char in LABEL (argument)", reader);
			break ;
		}
		i += 1;
		reader->j += 1;
	}
	if (!i)
		pars_error("Invalid char in LABEL (empty)", reader);
	return (i);
}

char			*get_label(t_read *reader)
{
	char	*line;
	char	*new;
	int		len;
	int		i;

	line = reader->arr[reader->i];
	len = label_len(reader);
	new = (char*)smart_malloc((len + 1) * sizeof(char));
	reader->j -= len;
	i = 0;
	while (i < len)
	{
		new[i] = line[reader->j];
		reader->j += 1;
		i += 1;
	}
	new[i] = 0;
	return (new);
}
