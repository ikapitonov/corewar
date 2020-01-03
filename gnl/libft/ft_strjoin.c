/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:55:58 by matruman          #+#    #+#             */
/*   Updated: 2019/09/20 17:58:24 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*res;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (s1 && s2) ? (char *)malloc(len1 + len2 + 1) : (char *)NULL;
	if (res)
	{
		ft_fstrncpy(res, s1, len1);
		ft_fstrncpy(res + len1, s2, len2);
		res[len1 + len2] = 0;
	}
	return (res);
}
