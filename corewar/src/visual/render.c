#include "corewar.h"

static void		render_bar(t_main *main)
{
	char 		*cycle;
	char 		*processes;
	char 		*cycle_to_die;
	
	cycle = ft_itoa(main->cycles_count);
	processes = ft_itoa(main->cursors);
	cycle_to_die = ft_itoa(main->cycle_to_die);
	mlx_string_put(main->mlx, main->win, WIDTH - 450, 160,
				   TEXT_COLOR, "Cycle : ");
	mlx_string_put(main->mlx, main->win, WIDTH - 450 + 80, 160,
				   TEXT_COLOR, cycle);
	mlx_string_put(main->mlx, main->win, WIDTH - 450, 190,
				   TEXT_COLOR, "Cursors : ");
	mlx_string_put(main->mlx, main->win, WIDTH - 450 + 100, 190,
				   TEXT_COLOR, processes);
	mlx_string_put(main->mlx, main->win, WIDTH - 450, 220,
				   TEXT_COLOR, "Cycle to die : ");
	mlx_string_put(main->mlx, main->win, WIDTH - 450 + 150, 220,
				   TEXT_COLOR, cycle_to_die);
	ft_strdel(&cycle);
	ft_strdel(&processes);
	ft_strdel(&cycle_to_die);
}

static void		render_plyer_info(t_main *main, int	i)
{
	char 		*number;
	char 		*processes;
	char 		*cycle_to_die;
	int 		color[4] = {CELL_PLAY_1, CELL_PLAY_2, CELL_PLAY_3, CELL_PLAY_4};
	
	number = ft_itoa(main->player[i].id);
	processes = ft_itoa(main->player[i].all_lives);
	cycle_to_die = ft_itoa(main->player[i].current_lives);
	mlx_string_put(main->mlx, main->win, WIDTH - 450, 280 + i * 130,
				   TEXT_COLOR, "Player ");
	mlx_string_put(main->mlx, main->win, WIDTH - 450 + 70, 280 + i * 130,
				   TEXT_COLOR, number);
	mlx_string_put(main->mlx, main->win, WIDTH - 450 + 90, 280 + i * 130,
				   color[i], main->player[i].name);
	mlx_string_put(main->mlx, main->win, WIDTH - 430, 310 + i * 130,
				   TEXT_COLOR, "Last live : ");
	mlx_string_put(main->mlx, main->win, WIDTH - 430 + 120, 310 + i * 130,
				   TEXT_COLOR, processes);
	mlx_string_put(main->mlx, main->win, WIDTH - 430, 340 + i * 130,
				   TEXT_COLOR, "Lives in current period : ");
	mlx_string_put(main->mlx, main->win, WIDTH - 430 + 260, 340 + i * 130,
				   TEXT_COLOR, cycle_to_die);
	ft_strdel(&number);
	ft_strdel(&processes);
	ft_strdel(&cycle_to_die);
}

static void		render_menu(t_main *main)
{
	mlx_string_put(main->mlx, main->win, WIDTH - 350, HEIGHT - 145,
				   TEXT_COLOR, "MENU");
	mlx_string_put(main->mlx, main->win, WIDTH - 380, HEIGHT - 120,
				   TEXT_COLOR, "Run / Pause - \"P\"");
	mlx_string_put(main->mlx, main->win, WIDTH - 380, HEIGHT - 100,
				   TEXT_COLOR, "Move one step - \"Space\"");
	mlx_string_put(main->mlx, main->win, WIDTH - 380, HEIGHT - 80,
				   TEXT_COLOR, "Speed - Press +/-");
	mlx_string_put(main->mlx, main->win, WIDTH - 380, HEIGHT - 60,
				   TEXT_COLOR, "Reset - \"R\"");
}

void			render(t_main *main)
{
	int 	i;
	
	render_background_inst(main);
	mlx_put_image_to_window(main->mlx, main->win, main->img, 0, 0);
	render_inst(main);
	render_bar(main);
	i = -1;
	while (++i < main->players)
		render_plyer_info(main, i);
	render_menu(main);
}