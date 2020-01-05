/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:27:19 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/03 16:27:20 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
void p(void) {printf("HELLO\n");}
static	void	common(t_main *main)
{
	parser(main);
	calc(main);
}

int				main(int ac, char *av[])
{
	t_main	*main;
	int		res;
	int		ch;

	if (ac < 2 || ac > 3 || !(res = check_args(ac, av)))
	{
		die("Usage: ./asm [-a] <your_sourcefile.s>");
	}
	if ((ch = open(av[res], O_RDONLY)) == -1)
	{
		die(ft_strjoin("Can't read source file ", av[res]));
	}
	main = init(ch);
	if (ac > 2)
		main->a_flag = 1;
	else
		main->filename = get_filename(av[res]);
	if (close(ch) == -1)
	{
		die(ft_strjoin("Can't close source file ", av[res]));
	}
	common(main);
	return (0);
}
