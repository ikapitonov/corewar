/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:07:31 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/04 17:07:32 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/asm.h"

void			error_position(char *first, char *second, int i, int j)
{
	int		fd;
	int		tmp;

	fd = 1;
	write(fd, first, ft_strlen(first));
	write(fd, "[", 1);
	tmp = 100;
	while (tmp / 10 && tmp > i)
	{
		write(fd, "0", 1);
		tmp /= 10;
	}
	ft_putnbr_fd(i, fd);
	write(fd, ":", 1);
	tmp = 100;
	while (tmp / 10 && tmp > j)
	{
		write(fd, "0", 1);
		tmp /= 10;
	}
	ft_putnbr_fd(j, fd);
	write(fd, "]", 1);
	if (second && second[0])
		write(fd, second, ft_strlen(second));
	write(fd, "\n", 1);
	exit(1);
}

void			die(const char *reason)
{
	int		fd;

	fd = 1;
	write(fd, reason, ft_strlen(reason));
	write(fd, "\n", 1);
	exit(1);
}
