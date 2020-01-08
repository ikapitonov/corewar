/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:11:55 by matruman          #+#    #+#             */
/*   Updated: 2019/11/25 16:11:58 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char				int_to_char(int d)
{
	if (d <= 9)
		return ('0' + d);
	else
		return ('a' + (d - 10));
}

int					u_numberlen(unsigned long long value, int base)
{
	int	i;

	i = 1;
	while (value / base)
	{
		value /= base;
		i++;
	}
	return (i);
}

unsigned long long	get_unsigned(long long value)
{
	unsigned long long	uval;

	if (value < 0)
	{
		uval = ~value;
		uval++;
	}
	else
		uval = value;
	return (uval);
}

char				*ft_itoa_base(unsigned long long value, int base)
{
	int					len;
	char				*str;

	if (base < 2 || base > 16)
		return (NULL);
	len = u_numberlen(value, base);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = 0;
	while (len)
	{
		str[len - 1] = int_to_char(value % base);
		value /= base;
		len--;
	}
	return (str);
}
