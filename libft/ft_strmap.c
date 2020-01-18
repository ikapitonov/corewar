/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:09:52 by matruman          #+#    #+#             */
/*   Updated: 2020/01/18 14:40:26 by bpole            ###   ########.fr       */
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
