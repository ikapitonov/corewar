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
# include "../../libft/includes/libft.h"
# include "../../includes/op.h"
# include <stdio.h>
# define COUNT_TOKENS 16
# define MAX_INT 2147483647
# define MAX_SHORT 32767
extern t_op g_instr[];

typedef struct		s_buffer
{
	char			*buff;
	int				used;
	int				size;
}					t_buffer;

typedef struct		s_main
{
	char			*name;
	char			*comment;
	char			a_flag;
	char			*filename;
	int				mark_flag;
	struct s_read	*reader;
	struct s_token	*last_token;
	struct s_token	*token;
	struct s_mark	*mark;
	struct s_mark	*last_mark;
	struct s_buffer buffer;
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
	int				set_index;
    struct s_token  *next;
}                   t_token;

typedef struct      s_mark
{
    char            *name;
    struct s_token  *token;
	struct s_mark	*mark;
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
void				pars_error(const char *str, t_read *reader);

void				*init(int ch);
int					check_args(int ac, char *av[]);
char				*get_filename(char *filename);

void				name_or_comment(t_main *main);
char				*full_string(t_main *main, t_read *reader,
									int length, int flag);

void				get_token(t_main *main, t_read *reader, int tmp);
void				*new_token(int index);
void				validate_arg(int index, int i, int needle, t_read *reader);
void				token_push(t_token *token, char type, int arg, char *mark);
void				save_registr(t_read *reader, t_token *token, int i, int index);
void				save_direct(t_read *reader, t_token *token, int i, int index);
void				save_indirect(t_read *reader, t_token *token, int i, int index);
char				*get_label(t_read *reader);

int					is_mark(char *line, t_read *reader);
int					ligth_is_mark(char *line);
void				get_mark(t_main *main, t_read *reader, int tmp);

char            	*file_get_contents(int ch);

void				parser(t_main *main);
void				valid_endline(t_read *reader);
void				analysis(t_main *main);

void				trim_str(char *str, int *i);
int					int_strchr(char *str);
int					is_empty(int c);
int					is_comment(int c);
int					args_exception(int c);

void				calc(t_main *main);

void				buffer_init(t_buffer *buffer, int size);
void				buffer_add(t_buffer	*buffer, char *str, int size);
void				rev_endian(void *val, int size);
void				set_header(t_main *main);
void				set_prog_size(t_main *main, int size);
char				set_arg_types(char *type);
void				write_to_file(t_main *main);
void				print_code_info(t_main *main, t_token *token, t_mark **marks, int i);
void				coder(t_main *main);

void p(void);
#endif
