/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:36:13 by matruman          #+#    #+#             */
/*   Updated: 2019/11/29 17:36:19 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t		ft_putstrn(const char *str, size_t n)
{
	size_t	i;
	size_t	len;
	size_t	size;

	i = 0;
	len = ft_strlen(str);
	size = 16;
	while (i < n / size && i < len / size)
	{
		write(1, str + i * size, size);
		i++;
	}
	i *= size;
	while (i < n && i < len)
	{
		write(1, str + i, 1);
		i++;
	}
	return (i);
}
