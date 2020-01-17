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
	char			s[] = "0123456789abcdef";
	unsigned char	*tab;
	unsigned long	i;
	unsigned long	res;
	
	i = 0;
	tab = (unsigned char*)addr;
	while (i < size)
	{
		write(1, s + tab[i] / 16, 1);
		write(1, s + tab[i] % 16, 1);
		i ++;
		if (i && i % 2 == 0)
			write(1, " ", 1);
		if (i && i % 64 == 0)
			put_ascii(tab, i - 64, i);
	}
	res = i - i / 16 * 16;
	if (i % 16)
	{
		put_sps(i % 16);
		put_ascii(tab, i - res, i);
	}
}