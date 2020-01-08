/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:31:51 by matruman          #+#    #+#             */
/*   Updated: 2019/11/13 20:31:53 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long_arithmetic.h"

t_big_int	*b_int_add(t_big_int *a, t_big_int *b)
{
	t_big_int	*res;
	t_big_int	*min;
	int			sum;
	int			mem;
	int			i;

	min = a->size < b->size ? a : b;
	b_int_copy(&res, min == a ? b : a);
	i = 0;
	mem = 0;
	while (i < min->size)
	{
		sum = res->arr[i] + min->arr[i] + mem;
		mem = sum >= BASE ? 1 : 0;
		res->arr[i] = sum < BASE ? sum : sum - BASE;
		i++;
	}
	if (mem)
		b_int_push(&res, mem);
	return (res);
}

int			b_int_mod(t_big_int *b_int, int d)
{
	t_big_int			*res;
	unsigned long long	n;
	unsigned long long	tmp;
	unsigned long long	mem;
	int					i;

	b_int_copy(&res, b_int);
	i = b_int->size;
	mem = 0;
	while (i--)
	{
		tmp = (res->arr)[i];
		n = mem * BASE + tmp;
		(res->arr)[i] = n / d;
		mem = n % d;
	}
	big_int_del(res);
	return (mem);
}

t_big_int	*b_int_div(t_big_int *b_int, int d)
{
	t_big_int			*res;
	unsigned long long	n;
	unsigned long long	tmp;
	unsigned long long	mem;
	int					i;

	b_int_copy(&res, b_int);
	i = b_int->size;
	mem = 0;
	while (i--)
	{
		tmp = (res->arr)[i];
		n = mem * BASE + tmp;
		(res->arr)[i] = n / d;
		mem = n % d;
	}
	if ((res->arr)[res->size - 1] == 0 && res->size > 1)
		b_int_unshift(&res);
	return (res);
}

t_big_int	*b_int_mult(t_big_int *b_int, int m)
{
	t_big_int			*res;
	unsigned long long	mult;
	int					i;
	unsigned long long	mem;

	b_int_copy(&res, b_int);
	i = 0;
	mem = 0;
	while (i < res->size)
	{
		mult = (unsigned long long)m * res->arr[i];
		res->arr[i] = (mult + mem) % BASE;
		mem = (mult + mem) / BASE;
		i++;
	}
	if (mem)
		b_int_push(&res, mem);
	return (res);
}
