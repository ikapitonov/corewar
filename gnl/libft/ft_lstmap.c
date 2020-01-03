/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:49:40 by matruman          #+#    #+#             */
/*   Updated: 2019/09/21 19:22:26 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	free_list(t_list *list)
{
	t_list	*next;

	while (list)
	{
		next = list->next;
		free(list->content);
		free(list);
		list = next;
	}
	return (1);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*tmp;

	if (lst)
	{
		tmp = f(lst);
		lst = lst->next;
		list = tmp;
	}
	else
		list = NULL;
	while (lst)
	{
		if (tmp)
		{
			tmp->next = f(lst);
			tmp = tmp->next;
		}
		else if (free_list(list))
			return ((t_list *)NULL);
		lst = lst->next;
	}
	return (list);
}
