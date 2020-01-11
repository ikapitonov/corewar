/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 20:06:53 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/09 20:06:54 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../../libft/includes/libft.h"
# include "../../includes/op.h"
# include <stdio.h>
# define COUNT_TOKENS 16
# define MAX_INT 2147483647
# define MAX_SHORT 32767

# define DUMP "dump"
# define DUMP_LEN 4
extern t_op g_instr[];

typedef struct		s_player
{
	char			*content;
	int				file_size;
	int				code_size;
	int				id;
}					t_player;

typedef struct		s_main
{
	struct s_player	player[MAX_PLAYERS];
	int				players;
	struct s_cursor	*cursor;
	struct s_cursor	*last_cursor;
	char			*area;
	int				dump;
}					t_main;

typedef struct		s_cursor
{
	int				registers[REG_NUMBER];
	int				pos;
	int				carry;
}					t_cursor;

typedef struct		s_read
{
	char			*str;
	size_t			size;
}					t_read;

void				*init();
void				init_player(t_main *main, int ch, int n);
void				die(const char *reason);

void				insert_params(t_main *main, int count_args, char *params[]);
int					valid_number(char *str);
int					is_number(int count_args, char *params[], int i);
void				help(void);
void				valid_filename(char *filename);

void p(void);
#endif
