/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:07:45 by matruman          #+#    #+#             */
/*   Updated: 2019/09/11 18:10:17 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*start;
	char	*res;

	i = 0;
	res = 0;
	start = (char *)s;
	while (s[i])
	{
		if (s[i] == (char)c)
			res = start + i;
		i++;
	}
	if (s[i] == (char)c)
		res = start + i;
	return (res);
}
