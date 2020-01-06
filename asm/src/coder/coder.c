/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 19:56:37 by matruman          #+#    #+#             */
/*   Updated: 2020/01/03 19:56:39 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

extern  t_op g_instr[];

int		find_mark(t_main *main, char *need, int pos)
{
	t_mark	*mark = main->mark;
	while (mark && !ft_strequ(mark->name, need))
		mark = mark->next;
	if (!mark)
		die("Mark error");
	return (mark->token->pos - pos);
}

void	get_marked_args(t_main *main, t_token *token)
{
	int		i;int j;

	i = 0;
	while (i < 3)
	{
		if (token->marks[i])
			token->arg[i] = find_mark(main, token->marks[i], token->pos);
		i++;
	}
}

void	rev_endian(void *val, int size)
{
	char	*p;
	char	tmp;
	int		i;

	p = (char *)val;
	i = 0;
	while (i < size / 2)
	{
		tmp = p[size - i - 1];
		p[size - i - 1] = p[i];
		p[i] = tmp;
		i++; 
	}
}

char	set_arg_types(char *type)
{
	char	code[3];
	char	res;
	int		i;

	i = 0;
	res = 0;
	while (i < 3)
	{
		if (type[i] == T_REG)
			code[i] = 1;
		else if (type[i] == T_DIR)
			code[i] = 2;
		else if (type[i] == T_IND)
			code[i] = 3;
		res = res | (code[i] << (6 - i * 2)); 
		i++;
	}
	return (res);
}

int		set_args(int arg, void *pos, int command, int type)
{
	int		i;
	short	s;

	if (type == T_REG)
	{
		*(char *)pos = (char)arg;
		return (1);
	}
	if (type == T_IND || (command > 8 && command < 16 && command != 0x0d))
	{
		s = (short)arg;
		rev_endian(&s, 2);
		*(short *)pos = s;
		return (2);
	}
	i = arg;
	rev_endian(&i, 4);
	*(int *)pos = i;
	return (4);
}

void		coder(t_main *main)
{
	t_token		*token;
	char		command[10];
	int			i;
	int			pos;

	token = main->token;
	while (token)
	{
		pos = 1;
		get_marked_args(main, token);
		command[0] = token->instruct;
		if (g_instr[command[0]].is_code_type && pos++)
			command[1] = set_arg_types(token->type);
		i = -1;
		while (++i < g_instr[command[0]].count_args)
			pos += set_args(token->arg[i], command + pos,
			command[0], token->type[i]);
		buffer_add(&main->buffer, command, pos);
		token = token->next;
	}
}
