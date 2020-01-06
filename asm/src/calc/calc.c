/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 22:01:35 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/05 22:01:37 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static	void	cacl_exec(t_token *token)
{
	int		res;
	int		i;
	
	res = g_instr[token->instruct].is_code_type ? 2 : 1;
	i = 0;
	while (i < 3)
	{
		if (token->type[i])
		{
			if (token->type[i] == T_REG)
				res += 1;
			else if (token->type[i] == T_DIR)
				res += g_instr[token->instruct].size_dir ? 2 : 4;
			else if (token->type[i] == T_IND)
				res += 2;
		}
		++i;
	}
	token->len = res;
}

void			calc(t_main *main)
{
	t_token	*token;
	t_token	*prev;

	prev = main->token;
	cacl_exec(prev);
	prev->pos = 0;
	token = main->token->next;
	while (token)
	{
		cacl_exec(token);
		token->pos = prev->pos + prev->len;
		prev = token;
		token = token->next;
	}

	// token = main->token;
	// while (token)
	// {
	// 	printf("%d  (%d)\n", token->pos, token->len);
	// 	token = token->next;
	// }
}
