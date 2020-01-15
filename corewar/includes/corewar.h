/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 20:06:53 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/11 21:32:38 by bpole            ###   ########.fr       */
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
# define HEADER_VAR 16
# define MIN_PLAYERS 2

# define T_REG_CODE 1
# define T_DIR_CODE 2
# define T_IND_CODE 3

extern t_op g_instr[];

typedef struct		s_player
{
	char			*content;
	int				file_size;
	int				code_size;
	int				id;
	char			*name;
	char			*comment;
	int				current_lives;
	int				all_lives;
}					t_player;

typedef struct		s_main
{
	struct s_player	player[MAX_PLAYERS];
	int				players;
	struct s_cursor	*cursor;
	struct s_cursor	*last_cursor;
	char			flag_a;
	char			*area;
	int				dump;
	int				cycle_to_die;
	int				cycles_count;
	int				current_cycle_to_die;
	int				last_player_id;
	int				lives_count;
	int				cursors;
	int				valids_count;
}					t_main;

typedef struct		s_cursor
{
	int				reg[REG_NUMBER];
	int				pos;
	int				command;
	int				cycles;
	char			types[3];
	int				carry;
	int				last_live_cycle;
	int				operation_code;
	int				cycles_to_wait;
	struct s_cursor	*next;
}					t_cursor;

typedef void	(*t_op_func) (t_main *main, t_cursor *cursor, char *area);
extern 				t_op_func op_arr[];

void				*init();
void				die(const char *reason);

void				init_player(t_main *main, int ch, int n);
void				calc_ids(t_main *main);

void				insert_params(t_main *main, int count_args, char *params[]);
int					valid_number(char *str);
int					is_number(int count_args, char *params[], int i);
void				help(void);
void				valid_filename(char *filename);
void				valid_file_size(char *str, int size);

void				memory_read(char *area, int pos, void *dst, int size);
void				memory_write(char *area, int pos, void *src, int size);
void				rev_endian(void *val, int size);
int32_t				memory_read_rev_endian(char *area, int pos, int size);
void				get_arg_types(char *typesarr, char *area, int pos);
int					check_arg_types(char *types, char command);


void				game_exec(t_main *main);

void    			live(t_main *main, t_cursor *cursor, char *area);
void    			ld(t_main *main, t_cursor *cursor, char *area);
void    			st(t_main *main, t_cursor *cursor, char *area);
void    			add(t_main *main, t_cursor *cursor, char *area);
void    			sub(t_main *main, t_cursor *cursor, char *area);
void    			and(t_main *main, t_cursor *cursor, char *area);
void    			or(t_main *main, t_cursor *cursor, char *area);
void    			xor(t_main *main, t_cursor *cursor, char *area);
void    			zjmp(t_main *main, t_cursor *cursor, char *area);
void    			ldi(t_main *main, t_cursor *cursor, char *area);
void    			sti(t_main *main, t_cursor *cursor, char *area);
void    			op_fork(t_main *main, t_cursor *cursor, char *area);
void    			lld(t_main *main, t_cursor *cursor, char *area);
void    			lldi(t_main *main, t_cursor *cursor, char *area);
void    			lfork(t_main *main, t_cursor *cursor, char *area);
void    			aff(t_main *main, t_cursor *cursor, char *area);



void				check_file_content(t_main *main, t_read *reader);
void				init_area(t_main *main);
void				init_cursors(t_main *main);

# define START_NAME 4
# define START_COMMENT (4 + PROG_NAME_LENGTH + 8)
# define CODE_SIZE_FILE 4
# define NULL_SIZE 4

void p(void);
#endif
