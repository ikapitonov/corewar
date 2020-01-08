/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:54:06 by matruman          #+#    #+#             */
/*   Updated: 2019/11/15 15:54:10 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long_arithmetic.h"

int			ft_pow(int n, int p)
{
	int		res;

	res = 1;
	while (p--)
		res *= n;
	return (res);
}

int			maxpower(int n)
{
	unsigned long long	maxp;
	int					i;

	i = 0;
	maxp = 1;
	while (maxp < BASE)
	{
		maxp *= n;
		i++;
	}
	i--;
	return (i);
}

t_big_int	*pow_div(t_big_int *big, int b, int pow)
{
	t_big_int	*res;
	t_big_int	*new;
	int			maxp;
	int			bmaxp;
	int			p;

	maxp = maxpower(b);
	bmaxp = ft_pow(b, maxp);
	p = 0;
	b_int_copy(&new, big);
	while ((p += maxp) < pow)
	{
		res = b_int_div(new, bmaxp);
		big_int_del(new);
		new = res;
	}
	p -= maxp;
	bmaxp = ft_pow(b, pow - p);
	res = b_int_div(new, bmaxp);
	big_int_del(new);
	return (res);
}

t_big_int	*pow_mult(t_big_int *big, int b, int pow)
{
	t_big_int	*res;
	t_big_int	*new;
	int			maxp;
	int			bmaxp;
	int			p;

	if (pow < 0)
		return (pow_div(big, b, -pow));
	maxp = maxpower(b);
	bmaxp = ft_pow(b, maxp);
	p = 0;
	b_int_copy(&new, big);
	while ((p += maxp) < pow)
	{
		res = b_int_mult(new, bmaxp);
		big_int_del(new);
		new = res;
	}
	p -= maxp;
	bmaxp = ft_pow(b, pow - p);
	res = b_int_mult(new, bmaxp);
	big_int_del(new);
	return (res);
}
