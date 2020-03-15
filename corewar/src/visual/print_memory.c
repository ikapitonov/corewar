/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 21:12:23 by bpole             #+#    #+#             */
/*   Updated: 2020/03/15 21:21:19 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	put_ascii(unsigned char *tab, unsigned long start, unsigned long finish)
{
	while (start < finish)
	{
		if (tab[start] >= 32 && tab[start] <= 126)
			write(1, tab + start, 1);
		else
			write(1, ".", 1);
		start++;
	}
	write(1, "\n", 1);
}

void	put_sps(unsigned long i)
{
	while (i < 16)
	{
		write(1, "  ", 2);
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
}

void	print_memory(const void *addr, size_t size)
{
	char			s[16];
	unsigned char	*tab;
	unsigned long	i;
	unsigned long	res;

	s = "0123456789abcdef";
	i = 0;
	tab = (unsigned char*)addr;
	while (i < size)
	{
		if (!(i % 64))
			ft_printf("%#06p : ", (uint64_t)i);
		write(1, s + tab[i] / 16, 1);
		write(1, s + tab[i] % 16, 1);
		i++;
		write(1, " ", 1);
		if (!(i % 64))
			write(1, "\n", 1);
	}
	res = i - i / 16 * 16;
	if (i % 16)
		put_sps(i % 16);
}
