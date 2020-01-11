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
int				main(int ac, char *av[])
{
	t_main	*main;

	main = (t_main*)init();
	insert_params(main, ac, av);
	return (0);
}
