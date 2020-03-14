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

void			ft_xor_exec(t_readf content, int fd, int *i)
{
	t_bits	data;

	data = ft_zero_struct();
	write(fd, "xor ", 4);
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

void			ft_zjmp_exec(t_readf content, int fd, int *i)
{
	write(fd, "zjmp ", 5);
	(*i)++;
	ft_t_dir_exec(content, fd, i, 1);
	write(fd, "\n", 1);
}

void			ft_ldi_exec(t_readf content, int fd, int *i)
{
	t_bits	data;

	data = ft_zero_struct();
	write(fd, "ldi ", 4);
	(*i)++;
	data.str[0] = content.str[*i];
	(*i)++;
	if (data.arr->a7 == 0 && data.arr->a6 == 1)
		ft_t_reg_exec(content, fd, i);
	else if (data.arr->a7 == 1 && data.arr->a6 == 1)
		ft_t_ind_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 1);
	write(fd, ", ", 2);
	if (data.arr->a5 == 0 && data.arr->a4 == 1)
		ft_t_reg_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 1);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, "\n", 1);
}

void			ft_sti_exec(t_readf content, int fd, int *i)
{
	t_bits	data;

	data = ft_zero_struct();
	write(fd, "sti ", 4);
	(*i)++;
	data.str[0] = content.str[*i];
	(*i)++;
	ft_t_reg_exec(content, fd, i);
	write(fd, ", ", 2);
	if (data.arr->a5 == 0 && data.arr->a4 == 1)
		ft_t_reg_exec(content, fd, i);
	else if (data.arr->a5 == 1 && data.arr->a4 == 1)
		ft_t_ind_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 1);
	write(fd, ", ", 2);
	if (data.arr->a3 == 0 && data.arr->a2 == 1)
		ft_t_reg_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 1);
	write(fd, "\n", 1);
}

void			ft_fork_exec(t_readf content, int fd, int *i)
{
	write(fd, "fork ", 5);
	(*i)++;
	ft_t_dir_exec(content, fd, i, 1);
	write(fd, "\n", 1);
}
