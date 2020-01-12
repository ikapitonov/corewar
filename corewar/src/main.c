/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 20:05:53 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/09 20:05:55 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
void p(void) {printf("HELLO\n");}
//./corewar -n 10 ../vm_champs/champs/jumper.cor

void			die(const char *reason)
{
	int		fd;

	fd = 1;
	if (reason && reason[0])
		write(fd, reason, ft_strlen(reason));
	write(fd, "\n", 1);
	exit(1);
}

void			test(t_main *main)
{
	// int i;

	// i = 0;
	// while (i < MEM_SIZE)
	// {
	// 	printf("%03d", main->area[i]);
	// 	if (!(i % 100))
	// 		printf("\n");
	// 	++i;
	// }
	int i;
	t_cursor *cursor;

	i = 0;
	cursor = main->cursor;
	while (cursor)
	{
		printf("%d\n", cursor->registers[0]);
		cursor = cursor->next;
	}
}

int				main(int ac, char *av[])
{
	t_main	*main;

	main = init();
	insert_params(main, ac, av);
	init_area(main);
	init_cursors(main);
//	game_exec(main);
	test(main);
	return (0);
}
