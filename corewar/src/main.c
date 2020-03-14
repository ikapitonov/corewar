/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 20:05:53 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/18 00:22:12 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
void p(void) {ft_printf("HELLO\n");}
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
		printf("%d\n", cursor->reg[0]);
		cursor = cursor->next;
	}
}

static int			cor_close(void *main)
{
	(void)main;
	exit(EXIT_SUCCESS);
}

int		init_mlx(t_main *main)
{
	if (!(main->mlx = mlx_init()) ||
		!(main->win = mlx_new_window(main->mlx, WIDTH, HEIGHT, "COREWAR")) ||
		!(main->img = mlx_new_image(main->mlx, WIDTH, HEIGHT)))
		return (0);
	main->data_addr = mlx_get_data_addr(main->img, &main->bits_per_pixel,
										&main->size_line, &main->endian);
	return (1);
}

void			print_winner(t_main *main)
{
	int		winner;
	int		i;

	winner = main->players;
	i = main->players;
	while(i)
	{
		if(main->player[main->p_index[i]].all_lives >
		main->player[main->p_index[winner]].all_lives)
		winner = i;
		i--;
	}
	ft_printf("Contestant %d, \"%s\", has won !\n", winner, main->player[main->p_index[winner]].name);
}

int				main(int ac, char *av[]) 
{
	t_main	*main;
	int		i;
	//clock_t start = clock();
	
	main = init();
	
	//main->start = start;
	
	insert_params(main, ac, av);
	if (main->flag_v)
		init_mlx(main);
	init_area(main);
	init_cursors(main);
	
	if (main->flag_v)
	{
		mlx_key_hook(main->win, lem_hook_keydown, main);
		mlx_hook(main->win, 17, 0, cor_close, main);
		mlx_loop_hook(main->mlx, lem_loop_key_hook, main);
		mlx_loop(main->mlx);
	}
	else
	{
		ft_putstr("Introducing contestants...\n");
		i = 0;
		while (++i <= main->players)
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			i, main->player[main->p_index[i]].code_size,
			main->player[main->p_index[i]].name, main->player[main->p_index[i]].comment);
		while (main->cursor && main->cycle_to_die > 0)
		{
			game_exec(main);
			if (main->dump && main->cycles_count == main->dump)
			{
				print_memory(main->area, MEM_SIZE);
				exit(0);
			}
		}
		if (main->cursor)
			game_exec(main);
		print_winner(main);
	}
	// int	i = 0;
	// cursor = main->cursor;
	// while (cursor)
	// {
	// 	p();
	// 	cursor = cursor->next;
	// }
//	printf(">%d\n", i);
//	test(main);
	return (0);
}
