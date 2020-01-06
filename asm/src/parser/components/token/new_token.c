/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:48:50 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/04 21:48:52 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/asm.h"

void			validate_arg(int index, int i, int needle, t_read *reader)
{
	if (i >= g_instr[index].count_args)
	{
		pars_error("Too much args", reader);
	}
	if (!(g_instr[index].args[i] & needle))
	{
		pars_error("Not found this arg", reader);
	}
}

void			token_push(t_token *token, char type, int arg, char *mark)
{
	int		i;

	i = token->set_index;
	token->type[i] = type;
	token->arg[i] = arg;
	token->marks[i] = mark;
}

void			*new_token(int index)
{
	t_token	*token;
	int		i;

	i = 0;
	token = (t_token*)smart_malloc(sizeof(t_token));
    token->len = 0;
    token->pos = 0;
	token->instruct = index;
	token->next = NULL;
	token->set_index = 0;
	while (i < 3)
	{
		token->type[i] = 0;
		token->marks[i] = NULL;
		token->arg[i] = 0;
		++i;
	}
	return ((void*)token);
}
