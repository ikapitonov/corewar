/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:28:54 by matruman          #+#    #+#             */
/*   Updated: 2019/10/06 18:37:12 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_atoi_fn(char c, int *sign)
{
	if (c == '-')
	{
		*sign = 1;
		return (1);
	}
	if (c == '+')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		j;
	int		sign;
	int		val;

	i = 0;
	while (str[i] == '\t' || str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = -1;
	if (ft_atoi_fn(str[i], &sign))
		i++;
	val = 0;
	while (str[i] == '0')
		i++;
	j = i;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		if (i - j > 17)
			return (sign < 0 ? -1 : 0);
		val = val * 10 - str[i] + '0';
		i++;
	}
	return (sign * val);
}
