/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:04:24 by matruman          #+#    #+#             */
/*   Updated: 2019/09/20 20:21:20 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr(int n)
{
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	if (n < 0 && n / 10 == 0)
		ft_putchar('-');
	if (n / 10)
		ft_putnbr(n / 10);
	ft_putchar('0' + (n % 10) * sign);
}
