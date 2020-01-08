/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:29:50 by matruman          #+#    #+#             */
/*   Updated: 2019/09/15 18:02:57 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*res;

	if (needle[0] == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			res = (char *)haystack;
			res = res + i;
			while (needle[j] == haystack[i + j] && needle[j])
				j++;
			if (needle[j] == 0)
				return (res);
		}
		i++;
	}
	return (NULL);
}
