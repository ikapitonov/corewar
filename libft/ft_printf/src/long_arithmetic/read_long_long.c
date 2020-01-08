/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_long_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:45:56 by matruman          #+#    #+#             */
/*   Updated: 2019/11/13 19:45:58 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long_arithmetic.h"

int			get_numsize(long long n)
{
	int		size;

	if (n == 0)
		return (1);
	size = 0;
	while (n)
	{
		n /= BASE;
		size++;
	}
	return (size);
}

int			get_unumsize(unsigned long long n)
{
	int		size;

	if (n == 0)
		return (1);
	size = 0;
	while (n)
	{
		n /= BASE;
		size++;
	}
	return (size);
}

t_big_int	*readll(long long n)
{
	t_big_int		*big_int;
	int				i;

	big_int = (t_big_int *)malloc(sizeof(t_big_int));
	if (!big_int)
		return (NULL);
	n > 0 ? big_int->sign = 1 : -1;
	big_int->size = get_numsize(n);
	big_int->arr = (int *)malloc(big_int->size * sizeof(int));
	if (!big_int->arr)
	{
		free(big_int);
		return (NULL);
	}
	i = 0;
	while (n)
	{
		(big_int->arr)[i] = big_int->sign * (n % BASE);
		n /= BASE;
		i++;
	}
	if (i == 0)
		(big_int->arr)[0] = 0;
	return (big_int);
}

t_big_int	*readll_u(unsigned long long n)
{
	t_big_int		*big_int;
	int				i;

	big_int = (t_big_int *)malloc(sizeof(t_big_int));
	if (!big_int)
		return (NULL);
	big_int->sign = 1;
	big_int->size = get_unumsize(n);
	big_int->arr = (int *)malloc(big_int->size * sizeof(int));
	if (!big_int->arr)
	{
		free(big_int);
		return (NULL);
	}
	i = 0;
	while (n)
	{
		(big_int->arr)[i] = n % BASE;
		n /= BASE;
		i++;
	}
	if (i == 0)
		(big_int->arr)[0] = 0;
	return (big_int);
}
