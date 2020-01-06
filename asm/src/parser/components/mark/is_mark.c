/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_mark.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:10:31 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/04 19:10:32 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/asm.h"

int				ligth_is_mark(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == LABEL_CHAR)
			return (i);
		if (!ft_strchr(LABEL_CHARS, line[i]))
			return (0);
		++i;
	}
	return (0);
}

int				is_mark(char *line, t_read *reader)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == LABEL_CHAR)
			return (i);
		if (!ft_strchr(LABEL_CHARS, line[i]))
			pars_error("Invalid char in LABEL (argument)", reader);
		++i;
	}
	return (0);
}
