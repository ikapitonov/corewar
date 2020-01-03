/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:15:00 by matruman          #+#    #+#             */
/*   Updated: 2019/09/19 20:15:51 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static void		ft_itoa_fn(char *str, int i, int n, int tmp)
{
	if (str)
	{
		str[i] = 0;
		i--;
		while (i >= 0)
		{
			str[i] = '0' + tmp * (n % 10);
			n /= 10;
			i--;
		}
		if (tmp < 0)
			str[0] = '-';
	}
}

char			*ft_itoa(int n)
{
	int		i;
	int		tmp;
	char	*str;

	tmp = n;
	i = 0;
	while (tmp || !i)
	{
		tmp /= 10;
		i++;
	}
	if (n < 0)
	{
		tmp = -1;
		i++;
	}
	else
		tmp = 1;
	str = (char *)malloc(i + 1);
	ft_itoa_fn(str, i, n, tmp);
	return (str);
}
