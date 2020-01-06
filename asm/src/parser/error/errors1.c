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

void			pars_error(const char *str, t_read *reader)
{
	int		fd;

	fd = 1;
	write(fd, str, ft_strlen(str));
	write(fd, " [", ft_strlen(" ["));
	ft_putnbr_fd(reader->i + 1, fd);
	write(fd, ":", 1);
	ft_putnbr_fd(reader->j + 1, fd);
	write(fd, "]\n", ft_strlen("]\n"));
	exit(1);
}

void			die(const char *reason)
{
	int		fd;

	fd = 1;
	if (reason && reason[0])
		write(fd, reason, ft_strlen(reason));
	write(fd, "\n", 1);
	exit(1);
}
