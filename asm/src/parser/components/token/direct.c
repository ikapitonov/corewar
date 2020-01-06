/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:21:12 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/05 17:21:14 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/asm.h"

static	int		direct_label_len(t_read *reader)
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

static	char	*direct_label_char(t_read *reader)
{
	char	*line;
	char	*new;
	int		len;
	int		i;

	line = reader->arr[reader->i];
	len = direct_label_len(reader);
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

static	int		direct_int(t_read *reader, long long max)
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
			pars_error("Argument \"T_DIR\": Value too much", reader);
	}
	if (args_exception(line[reader->j]))
		pars_error("Argument \"T_DIR\" must be a number", reader);
	return (num * tmp);
}

void			save_direct(t_read *reader, t_token *token,
							int i, int index)
{
	char	*line;
	char	*c_res;
	int		res;

	c_res = NULL;
	res = 0;
	validate_arg(index, i, T_DIR, reader);
	line = reader->arr[reader->i];
	reader->j += 1;
	if (line[reader->j] == LABEL_CHAR)
	{
		reader->j += 1;
		c_res = direct_label_char(reader);
	}
	else if (ft_isdigit(line[reader->j]) || line[reader->j] == '-')
		res = direct_int(reader, g_instr[index].size_dir ? MAX_SHORT
														: MAX_INT);
	else
		pars_error("Argument \"T_DIR\": incorrectly value", reader);
	token->set_index = i;
	token_push(token, T_DIR, res, c_res);
}
