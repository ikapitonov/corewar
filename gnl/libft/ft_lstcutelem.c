/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcutelem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:06:52 by matruman          #+#    #+#             */
/*   Updated: 2019/10/05 13:28:15 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstcutelem(t_list *list, t_list **first)
{
	t_list	*prev;
	t_list	*next;

	prev = *first;
	next = list->next;
	if (prev == list)
	{
		free(list->content);
		free(list);
		*first = next;
		return ;
	}
	while (prev->next != list)
		prev = prev->next;
	free(list->content);
	free(list);
	prev->next = next;
}
