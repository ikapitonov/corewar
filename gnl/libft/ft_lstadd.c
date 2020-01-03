/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:39:43 by matruman          #+#    #+#             */
/*   Updated: 2019/09/21 16:24:00 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*lst;

	lst = alst ? *alst : NULL;
	if (alst && new)
	{
		new->next = lst;
		*alst = new;
	}
}
