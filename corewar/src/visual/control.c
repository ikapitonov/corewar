#include "corewar.h"

static void		put_pause(t_main *main)
{
	if (main->pause == 0)
		main->pause = 1;
	else
		main->pause = 0;
}

static void		reset(t_main *main)
{

}

static void		speed_control(int key, t_main *main)
{
	if (key == NUM_PAD_PLUS)
	{
		if (main->speed == 0)
			main->speed = 0;
		else
			main->speed--;
	}
	if (key == NUM_PAD_MINUS)
		main->speed++;
}

int				lem_hook_keydown(int key, t_main *main)
{
	if (key == MAIN_PAD_ESC)
		exit(EXIT_SUCCESS);
	if (key == MAIN_PAD_P)
		put_pause(main);
	if (key == MAIN_PAD_R)
		reset(main);
	if (key == MAIN_PAD_SPACE)
		main->one_step = 1;
	if (key == NUM_PAD_MINUS || key == NUM_PAD_PLUS)
		speed_control(key, main);
	render(main);
	return (0);
}