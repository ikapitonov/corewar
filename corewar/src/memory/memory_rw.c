/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_rw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:49:44 by matruman          #+#    #+#             */
/*   Updated: 2020/01/11 17:49:47 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		rev_endian(void *val, int size)
{
	char	*p;
	char	tmp;
	int		i;

	p = (char *)val;
	i = 0;
	while (i < size / 2)
	{
		tmp = p[size - i - 1];
		p[size - i - 1] = p[i];
		p[i] = tmp;
		i++; 
	}
}

int32_t		memory_read_rev_endian(char *area, int pos, int size)
{
	int32_t	res;

	res = 0;
	memory_read(area, pos, &res, size);
	rev_endian(&res, size);
	return (res);
}

void		memory_read(char *area, int pos, void *dst, int size)
{
	int		i;
	char	*cdst;

	cdst = (char *)dst;
	i = 0;
	while (i < size)
	{
		cdst[i] = area[(pos + i) % MEM_SIZE];
		i++;
	}
}

void	memory_write(t_main *main, int player, char *area, int pos, void *src, int size)
{
	int		i;
	char	*csrc;
	
	i = 0;
	csrc = (char *)src;
	while (i < size)
	{
		area[(pos + i) % MEM_SIZE] = 1;		//  csrc[i]
		main->cell[(pos + i) % MEM_SIZE].player = player;
		i++;
	}
}
