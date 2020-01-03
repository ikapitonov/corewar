/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstrncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:55:12 by matruman          #+#    #+#             */
/*   Updated: 2019/11/29 15:55:18 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fstrncpy(char *dst, const char *src, size_t len)
{
	size_t		i;
	long long	*lsrc;
	long long	*ldst;

	i = 0;
	lsrc = (long long *)src;
	ldst = (long long *)dst;
	while (i < len / sizeof(long long))
	{
		ldst[i] = lsrc[i];
		i++;
	}
	i = i * sizeof(long long);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}
