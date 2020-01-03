/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:21:38 by matruman          #+#    #+#             */
/*   Updated: 2019/09/20 18:31:44 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*res;

	if (s && f)
	{
		res = (char *)malloc(ft_strlen(s) + 1);
		if (res)
		{
			i = 0;
			while (s[i])
			{
				res[i] = f(i, s[i]);
				i++;
			}
			res[i] = 0;
		}
	}
	return ((s && f) ? res : (char *)NULL);
}
