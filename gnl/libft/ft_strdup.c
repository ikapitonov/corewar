/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:10:25 by matruman          #+#    #+#             */
/*   Updated: 2019/09/19 18:49:30 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	my_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char			*ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;
	size_t	size;

	size = my_strlen(s1) + 1;
	res = (char *)malloc(size);
	if (res)
	{
		i = 0;
		while (i < size)
		{
			res[i] = s1[i];
			i++;
		}
		return (res);
	}
	else
		return (NULL);
}
