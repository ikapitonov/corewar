/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:26:58 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/03 16:26:59 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "../../gnl/get_next_line.h"
# include <stdio.h>

typedef struct		s_main
{
	int				lines;
	char			*name;
	char			*comment;
	struct s_token	*token;
	struct s_mark	*mark;
}					t_main;

typedef struct		s_token
{
	int				len;
	int				sub;
	int				instruct;
	char			type_1;
	char			type_2;
	char			type_3;
	int				val_1;
	int				val_2;
	int				val_3;
	char			*marks[3];
	struct s_token	*next;
}					t_token;

typedef struct		s_mark
{
	int i;
}					t_mark;

typedef struct		s_pars
{
	t_main			*main;
	int				ch;
	char			**line;
}					t_pars;

void				die(const char *reason);
void				*smart_malloc(size_t how_much);
void				error_position(char *first, char *second,
									int i, int j);

void				*init();

void				parser(t_main *main, char **line, int ch);

void				name_or_comment(t_pars *pars, int i);
void				full_string(char *new, t_pars *pars, int *i, int len);

void				trim_str(char *str, int *i);
void p(void);
#endif
