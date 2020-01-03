/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:28:43 by matruman          #+#    #+#             */
/*   Updated: 2019/09/21 16:47:32 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*next;

	lst = alst ? *alst : NULL;
	if (lst)
	{
		while (lst)
		{
			next = lst->next;
			del(lst->content, lst->content_size);
			free(lst);
			lst = next;
		}
		*alst = NULL;
	}
}
