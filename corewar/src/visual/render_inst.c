#include "corewar.h"

static void		drow_sqw(t_main *main, int x, int y, unsigned long cell)
{
	int 	w;
	int 	h;
	int			i;
	int 	color;
	int 	colors[5] = {CELL_DEF, CELL_PLAY_1, CELL_PLAY_2, CELL_PLAY_3, CELL_PLAY_4};
	
	h = 16;
	while (h)
	{
		w = 16;
		while (w)
		{
			i = x + w + (y + h) * WIDTH;
			color = colors[main->cell[cell].player];
			if (main->cell[cell].cursor)
				color |= CURSOR;
			if (0 < x + w && x + w < WIDTH && 0 < y + h && y + h < HEIGHT)
				((int *)(main->data_addr))[i] = color;
			w--;
		}
		h--;
	}
}

void		render_background_inst(t_main *main)
{
	int		i;
	int		x;
	int		y;
	
	i = 0;
	x = 30;
	y = 30;
	while (i < MEM_SIZE)
	{
		drow_sqw(main, x - 3, y + 2, i);
		i ++;
		x += 20;
		if (i && i % LEN == 0)
		{
			y += 20;
			x = 30;
		}
	}
}

void				render_inst(t_main *main)
{
	char 			str[2];
	unsigned char	*tab;
	unsigned long	i;
	int x;
	int y;
	
	i = 0;
	x = 30;
	y = 30;
	str[1] = '\0';
	tab = (unsigned char*)main->area;
	while (i < MEM_SIZE)
	{
		if (tab[i] > 0 && tab[i] < 17)
			str[0] = REG_SYMBOL[tab[i] - 1];
		else
			str[0] = '\0';
		mlx_string_put(main->mlx, main->win, x, y,
					   TEXT_COLOR, str);
		i ++;
		x += 20;
		if (i && i % LEN == 0)
		{
			y += 20;
			x = 30;
		}
	}
}