/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:00:17 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/05 19:00:18 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/asm.h"

static	int		indirect_int(t_read *reader, long long max)
{
	long long int	num;
	char			*line;
	short			tmp;

	line = reader->arr[reader->i];
	num = 0;
	tmp = 1;
	if (line[reader->j] == '-')
	{
		tmp = -1;
		reader->j += 1;
	}
	while (line[reader->j] >= '0' && line[reader->j] <= '9')
	{
		num = (num * 10) + (line[reader->j] - '0');
		reader->j += 1;
		if ((tmp > 0 && num > max) || (tmp < 0 && num + 1 > max + 1))
			pars_error("Argument \"T_IND\": Value too much", reader);
	}
	if (args_exception(line[reader->j]))
		pars_error("Argument \"T_IND\" must be a number", reader);
	return (num * tmp);
}

void			save_indirect(t_read *reader, t_token *token,
								int i, int index)
{
	char	*line;
	int		res;
	char	*c_res;

	res = 0;
	c_res = NULL;
	validate_arg(index, i, T_IND, reader);
	line = reader->arr[reader->i];
<<<<<<< HEAD
	res = indirect_int(reader, MAX_INT);
=======
	if (line[reader->j] == LABEL_CHAR)
	{
		reader->j += 1;
		c_res = get_label(reader);
	}
	else
		res = indirect_int(reader, MAX_INT);
>>>>>>> origin/ilya
	token->set_index = i;
	token_push(token, T_IND, res, c_res);
}
