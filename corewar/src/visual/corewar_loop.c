#include "corewar.h"

void	count_coursor(t_main *main)
{
	t_cursor	*cursor;
	int 		i;
	
	i = -1;
	while (++i < MEM_SIZE)        //  удаляем метки пребывания курсоров в ячейках
		main->cell[i].cursor = 0;
	cursor = main->cursor;
	main->cursors = 0;
	while (cursor)
	{
		main->cursors++;
		//ft_printf("%d\n", cursor->pos);
		main->cell[cursor->pos].cursor = 1;		// добовляем метки
		cursor = cursor->next;
	}
}

int				lem_loop_key_hook(t_main *main)
{
	char		*str;
	static int 		i;
	
	str = "RUN";
	i > main->speed ? i = 0 : i++;
	if (((!i && main->pause == 1) || main->one_step))
	{
		main->one_step = 0;
		if (main->cursor && main->cycle_to_die > 0)
			game_exec(main);
		count_coursor(main);
		render(main);
		print_memory(main->area, MEM_SIZE);
		ft_printf("\n");
	}
	else
		render(main);
	if (main->pause == 0)
		str = "PAUSE";
	mlx_string_put(main->mlx, main->win,
				   WIDTH - 350, 50, TEXT_COLOR, str);
	return (0);
}