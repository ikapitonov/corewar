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

void			ft_st_exec(t_readf content, int fd, int *i)
{
	t_bits	data;

	data = ft_zero_struct();
	write(fd, "st ", 3);
	(*i)++;
	data.str[0] = content.str[*i];
	(*i)++;
	ft_t_reg_exec(content, fd, i);
	write(fd, ", ", 2);
	if (data.arr->a5 == 0)
		ft_t_reg_exec(content, fd, i);
	else
		ft_t_ind_exec(content, fd, i);
	write(fd, "\n", 1);
}

void			ft_add_exec(t_readf content, int fd, int *i)
{
	write(fd, "add ", 4);
	(*i)++;
	(*i)++;
	ft_t_reg_exec(content, fd, i);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, "\n", 1);
}

void			ft_sub_exec(t_readf content, int fd, int *i)
{
	write(fd, "sub ", 4);
	(*i)++;
	(*i)++;
	ft_t_reg_exec(content, fd, i);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, "\n", 1);
}

void			ft_and_exec(t_readf content, int fd, int *i)
{
	t_bits	data;

	data = ft_zero_struct();
	write(fd, "and ", 4);
	(*i)++;
	data.str[0] = content.str[*i];
	(*i)++;
	if (data.arr->a7 == 0 && data.arr->a6 == 1)
		ft_t_reg_exec(content, fd, i);
	else if (data.arr->a7 == 1 && data.arr->a6 == 1)
		ft_t_ind_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 3);
	write(fd, ", ", 2);
	if (data.arr->a5 == 0 && data.arr->a4 == 1)
		ft_t_reg_exec(content, fd, i);
	else if (data.arr->a5 == 1 && data.arr->a4 == 1)
		ft_t_ind_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 3);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, "\n", 1);
}

void			ft_or_exec(t_readf content, int fd, int *i)
{
	t_bits	data;

	data = ft_zero_struct();
	write(fd, "or ", 3);
	(*i)++;
	data.str[0] = content.str[*i];
	(*i)++;
	if (data.arr->a7 == 0 && data.arr->a6 == 1)
		ft_t_reg_exec(content, fd, i);
	else if (data.arr->a7 == 1 && data.arr->a6 == 1)
		ft_t_ind_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 3);
	write(fd, ", ", 2);
	if (data.arr->a5 == 0 && data.arr->a4 == 1)
		ft_t_reg_exec(content, fd, i);
	else if (data.arr->a5 == 1 && data.arr->a4 == 1)
		ft_t_ind_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 3);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, "\n", 1);
}
