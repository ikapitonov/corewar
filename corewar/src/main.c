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

void			test(t_main *main)
{
	int i;

	i = 0;
	while (i < main->players)
	{
		printf("%d %d\n", main->player[i].file_size, main->player[i].code_size);
		++i;
	}
}

int				main(int ac, char *av[])
{
	t_main	*main;

	main = (t_main*)init();
	insert_params(main, ac, av);
	test(main);
	return (0);
}
