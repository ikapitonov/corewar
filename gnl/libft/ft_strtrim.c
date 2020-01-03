/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:47:23 by matruman          #+#    #+#             */
/*   Updated: 2019/09/20 18:27:24 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		skip_blanks(int *i, int *j, char const *s)
{
	while (s[*i] == ' ' || s[*i] == '\t' || s[*i] == '\n')
		(*i)++;
	*j = *i;
	while (s[*j + 1])
		(*j)++;
	while ((s[*j] == ' ' || s[*j] == '\t' || s[*j] == '\n') && *j)
		(*j)--;
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	i = 0;
	if (s)
	{
		skip_blanks(&i, &j, s);
		if (j > i)
			res = (char *)malloc(j - i + 2);
		else
			res = (char *)malloc(1);
		k = 0;
		if (res)
		{
			while (i <= j)
				res[k++] = s[i++];
			res[k] = 0;
		}
	}
	return (s ? res : (char *)NULL);
}
