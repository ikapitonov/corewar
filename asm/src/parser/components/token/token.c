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
        if (!ft_strncmp(line, g_instr[i].name, position))
        {
            return (i);
        }
        ++i;
    }
    return (-1);
}

static	void	clean_after_arg(t_read *reader)
{
	char	*line;

	line = reader->arr[reader->i];
	trim_str(reader->arr[reader->i], &reader->j);
	// while (args_exception(line[reader->j]))
	// 	reader->j += 1;
	if (line[reader->j] == SEPARATOR_CHAR)
		reader->j += 1;
}

static  void    token_info(t_main *main, t_read *reader, int index, t_token *token)
{
	char	*line;
    int     i;

	i = 0;
	while (i < g_instr[index].count_args)
	{
		trim_str(reader->arr[reader->i], &reader->j);
		line = reader->arr[reader->i] + reader->j;
        if (*line == 'r')
			save_registr(reader, token, i, index);
        else if ((*line == '-' && ft_isdigit(line[1]))
			|| ft_isdigit(*line) || *line == LABEL_CHAR)
        	save_indirect(reader, token, i, index);
        else if (*line == DIRECT_CHAR)
            save_direct(reader, token, i, index);
        else
            pars_error("Invalid argument", reader);
		clean_after_arg(reader);
        ++i;
	}
	if (i != g_instr[index].count_args)
		pars_error("Few arguments", reader);
}

void			get_token(t_main *main, t_read *reader, int tmp)
{
	t_token	*token;
    int     index;

	if (!main->name || !main->comment)
		pars_error("Undefined Champion name or comment", reader);
    if ((index = is_token(reader->arr[reader->i] + reader->j, tmp)) == -1)
	{
		(reader->arr[reader->i] + reader->j)[tmp] = 0;
        pars_error(ft_strjoin("Invalid instruction: ",
					reader->arr[reader->i] + reader->j), reader);
	}
	token = new_token(index);
    reader->j += tmp;
    token_info(main, reader, index, token);
	valid_endline(reader);
	if (main->last_token)
	{
		main->last_token->next = token;
		main->last_token = token;
		return ;
	}
	main->token = token;
	main->last_token = token;
}
