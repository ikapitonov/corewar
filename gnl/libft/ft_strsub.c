/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:37:58 by matruman          #+#    #+#             */
/*   Updated: 2019/09/20 17:31:47 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	sub = (char *)malloc(len + 1);
	if (sub && s)
	{
		i = 0;
		while (i < len)
		{
			sub[i] = s[start + i];
			i++;
		}
		sub[i] = 0;
	}
	return (sub);
}
