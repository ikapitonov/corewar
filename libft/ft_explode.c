/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_explode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:07:31 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/06 17:07:32 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static	int		get_count(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == c)
		{
			++count;
		}
		++i;
	}
	return (count);
}

static	int		get_len(char *str, char c, int i)
{
	int		j;

	j = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (++j);
		}
		++j;
		++i;
	}
	return (j);
}

static	void	push_str(char *to, char *from, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		to[i] = from[i];
		++i;
	}
	to[i] = 0;
}

char			**ft_explode(char *str, char c)
{
	int		count;
	int		tmp;
	int		i;
	int		j;
	char	**arr;

	if (!str || !c)
		return (NULL);
	count = get_count(str, c);
	if (!(arr = (char**)malloc(sizeof(void*) * (count + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < count)
	{
		tmp = get_len(str, c, i);
		if (!(arr[j] = (char*)malloc((tmp + 1) * sizeof(char))))
			return (NULL);
		push_str(arr[j], str + i, j + 1 == count ? tmp : tmp - 1);
		i += tmp;
		++j;
	}
	arr[count] = NULL;
	return (arr);
}
