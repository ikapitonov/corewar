/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:27:55 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/05 15:27:58 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/asm.h"

static	int		registr_atoi(t_read *reader)
{
	char	*line;
	size_t	num;
	
	num = 0;
	line = reader->arr[reader->i];
	if (!ft_isdigit(line[reader->j]))
		die("Syntax error at registr_atoi");
	while (line[reader->j] >= '0' && line[reader->j] <= '9')
	{
		num = (num * 10) + (long long int)(line[reader->j] - '0');
		reader->j += 1;
	}
	if (args_exception(line[reader->j]))
		die("Syntax error at registr_atoi");
	if (num < 1 || num > REG_NUMBER)
		die("Syntax error at registr_atoi");
	return (num);
}

void			save_registr(t_read *reader, t_token *token, int i, int index)
{
	char	*line;
	int		res;

	validate_arg(index, i, T_REG, reader);
	line = reader->arr[reader->i] + reader->j;
	reader->j += 1;
	res = registr_atoi(reader);
	token->set_index = i;
	token_push(token, T_REG, res, NULL);
}
