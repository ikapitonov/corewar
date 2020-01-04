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

static	void	new_token_null(t_token *token)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		token->type[i] = 0;
		token->arg[i] = 0;
		++i;
	}
}

void			*new_token(int index)
{
	t_token	*token;

	token = (t_token*)smart_malloc(sizeof(t_token));
    token->len = 0;
    token->pos = 0;
	token->instruct = index;
	new_token_null(token);
//	token->marks = NULL;
	token->next = NULL;
	return ((void*)token);
}
