/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:27:29 by matruman          #+#    #+#             */
/*   Updated: 2019/09/20 20:25:10 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	if (n < 0 && n / 10 == 0)
		ft_putchar_fd('-', fd);
	if (n / 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd('0' + (n % 10) * sign, fd);
}
