/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 23:02:18 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/03 23:02:19 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/asm.h"

static	void	max_len(j)
{

}

static	int		str_write(char *line, int *i, char *new, int *j)
{
	while (line[*i] != '=' && line[*i])
	{
		new[*j] = line[*i];
		*j += 1;
		*i += 1;
	}
	return (line[*i] == '=' ? 0 : 1);
}

void			full_string(char *new, t_pars *pars, int *i, int len)
{
	char	*line;
	int		j;

	j = 0;
	line = *pars->line + *i;
	while (str_write(line, i, new, &j))
	{
		
	}
}    
