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
# define COUNT_TOKENS 16
extern t_op g_instr[];

typedef struct		s_main
{
	char			*name;
	char			*comment;
	struct s_read	*reader;
	struct s_token	*token;
	struct s_mark	*mark;
}					t_main;

typedef struct		s_read
{
	char			*str;
	char			**arr;
	int				count;
	int				i;
	int				j;
}					t_read;

typedef struct      s_token
{
    int             len;
    int             pos;
    int             instruct;
    char            type[3];
    int             arg[3];
    char            *marks[3];
    struct s_token  *next;
}                   t_token;

typedef struct      s_mark
{
    char            *name;
    struct s_token  *token;
    struct s_mark   *next;
}                   t_mark;

typedef struct		s_join
{
	char			*str;
	size_t			length;
	struct s_join	*next;
}					t_join;

void				die(const char *reason);
void				*smart_malloc(size_t how_much);
void				error_position(char *first, char *second,
									int i, int j);

void				*init();

void				name_or_comment(t_main *main);
char				*full_string(t_main *main, t_read *reader,
									int length, int flag);

void				token(t_main *main, t_read *reader, int tmp, char *line);
void				*new_token(int index);

int					is_mark(char *line, int i);

char            	*file_get_contents(int ch);
void				parser(t_main *main);
void				trim_str(char *str, int *i);
int					int_strchr(char *str);
int					is_empty(int c);


void p(void);
#endif
