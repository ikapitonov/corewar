/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:29:14 by matruman          #+#    #+#             */
/*   Updated: 2019/09/15 19:57:08 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	i = 0;
	while (s1[i] && i < size)
		i++;
	len1 = i;
	len2 = ft_strlen(s2);
	j = 0;
	if (!size)
		return (len1 + len2);
	while (s2[j] && i < size - 1)
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	if (len1 < size)
		s1[i] = 0;
	return (len1 + len2);
}
