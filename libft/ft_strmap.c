/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:09:52 by matruman          #+#    #+#             */
/*   Updated: 2019/09/20 18:32:13 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*res;

	if (s && f)
	{
		res = (char *)malloc(ft_strlen(s) + 1);
		if (res && s && f)
		{
			i = 0;
			while (s[i])
			{
				res[i] = f(s[i]);
				i++;
			}
			res[i] = 0;
		}
	}
	return ((s && f) ? res : (char *)NULL);
}
