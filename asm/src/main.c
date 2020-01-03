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

static	void	common(t_main *main)
{
	return ;
}

int				main(int ac, char *av[])
{
	t_main	*main;
	int		ch;
	char	*line;

	if (ac < 2)
		die("Usage: lalala");
	if ((ch = open(av[1], O_RDONLY)) == -1)
		die(ft_strjoin("Can't read source file ", av[0]));
	line = NULL;
	main = init();
	while (get_next_line(ch, &line) > 0)
	{
		parser(main, &line, ch);
		ft_memdel((void**)&line);
	}
	// if (!main->name)
	// 	die(ft_strjoin("Can't read source file ", av[0]));
	close(ch);
	common(main);
	return 0;
}
