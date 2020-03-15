/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrowzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:55:27 by edrowzee          #+#    #+#             */
/*   Updated: 2020/01/18 14:55:28 by edrowzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"
#include "disassembly.h"

void			ft_t_dir_exec(t_readf content, int fd, int *i, int size)
{
	t_bits	data;
	int		a;

	a = size;
	data = ft_zero_struct();
	while (size >= 0)
	{
		data.str[size] = content.str[*i];
		(*i)++;
		size--;
	}
	if (data.arr[1].a7 == 1 && a == 1)
		data.num -= 65536;
	write(fd, "%", 1);
	ft_putnbr_fd(data.num, fd);
}

void			ft_t_reg_exec(t_readf content, int fd, int *i)
{
	t_bits	data;

	data = ft_zero_struct();
	data.str[0] = content.str[*i];
	(*i)++;
	write(fd, "r", 1);
	ft_putnbr_fd(data.num, fd);
}

void			ft_t_ind_exec(t_readf content, int fd, int *i)
{
	t_bits	data;
	int		j;
	int		result;

	j = 1;
	data = ft_zero_struct();
	while (j >= 0)
	{
		data.str[j] = content.str[*i];
		(*i)++;
		j--;
	}
	result = data.num;
	if (data.arr[1].a7 == 1)
		result -= 65536;
	ft_putnbr_fd(result, fd);
}

void			ft_live_exec(t_readf content, int fd, int *i)
{
	write(fd, "live ", 5);
	(*i)++;
	ft_t_dir_exec(content, fd, i, 3);
	write(fd, "\n", 1);
}

void			ft_ld_exec(t_readf content, int fd, int *i)
{
	t_bits	data;

	data = ft_zero_struct();
	write(fd, "ld ", 3);
	(*i)++;
	data.str[0] = content.str[*i];
	(*i)++;
	if (data.arr->a6 == 0)
		ft_t_dir_exec(content, fd, i, 3);
	else
		ft_t_ind_exec(content, fd, i);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, "\n", 1);
}
