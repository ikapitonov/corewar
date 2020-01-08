/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_code_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:11:24 by matruman          #+#    #+#             */
/*   Updated: 2020/01/06 20:11:26 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void    print_marks(t_token *token, t_mark *mark)
{
	while (mark && mark->token != token)
		mark = mark->next;
	if (!mark)
		return ;
	recursive_mark_print(mark->name);
}

t_mark	**get_mark_array(t_mark *start)
{
	int		count;
	t_mark	*mark;
	t_mark	**arr;

	mark = start;
	count = 0;
	while (mark)
	{
		mark = mark->next;
		count++;
	}
	arr = (t_mark **)smart_malloc(count * sizeof(t_mark *));
	mark = start;
	count = 0;
	while (mark)
	{
		arr[count] = mark;
		mark = mark->next;
		count++;
	}
	return (arr);
}

void	print_code_info(t_main *main)
{
	t_token     *token;

	token = main->token;
	print_marks(token, main->mark);
}
