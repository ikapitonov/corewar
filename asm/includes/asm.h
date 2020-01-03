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

void				die(const char *reason);
void				*smart_malloc(size_t how_much);

void				*init();

void				parser(t_main *main, char *line);

#endif
