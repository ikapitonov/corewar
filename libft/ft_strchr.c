/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:43:54 by matruman          #+#    #+#             */
/*   Updated: 2020/01/12 18:15:15 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*start;

	i = 0;
	start = (char *)s;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (start + i);
		i++;
	}
	if (s[i] == (char)c)
		return (start + i);
	return (0);
}
