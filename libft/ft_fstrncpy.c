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
#include <stdio.h>

void	ft_fstrncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}
