/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:31:52 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/03 17:31:53 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			die(const char *reason)
{
	int		fd;

	fd = 1;
	write(fd, reason, ft_strlen(reason));
	write(fd, "\n", 1);
	exit(1);
}

void			*smart_malloc(size_t how_much)
{
	void	*new;

	if (!(new = malloc(how_much)))
	{
		ft_putstr("malloc() does not work");
		exit(1);	
	}
	return (new);
}

void			*init()
{
	t_main	*main;

	main = (t_main*)smart_malloc(sizeof(t_main));
	main->name = NULL;
	main->comment = NULL;
	main->token = NULL;
	main->mark = NULL;
	return ((void*)main);
}
