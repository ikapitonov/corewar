/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:06:44 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/17 23:50:02 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			*smart_malloc(size_t how_much)
{
	void	*new;

	if (!(new = ft_memalloc(how_much)))
	{
		ft_putstr("malloc() does not work\n");
		exit(1);
	}
	return (new);
}
