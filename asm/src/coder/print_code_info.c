/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_code_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:11:24 by matruman          #+#    #+#             */
/*   Updated: 2020/01/06 20:11:26 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	recursive_mark_print(t_mark **marks, int pos, int i)
{
	if (i - 1 >= 0 && marks[i - 1]->mark)
		recursive_mark_print(marks, pos, i - 1);
	ft_printf("%-11d:    %s:\n", pos, marks[i]->name);
}

void    print_marks(t_token *token, t_mark **marks)
{
	int		i;

	i = 0;
	while (marks[i] && marks[i]->token != token)
		i++;
	if (!marks[i])
		return ;
	recursive_mark_print(marks, token->pos, i);
}

t_mark	**get_mark_array(t_mark *start)
{
	int		count;
	t_mark	*mark;
	t_mark	**arr;

	mark = start;
	count = 0;
	while (mark)
	{
		mark = mark->next;
		count++;
	}
	arr = (t_mark **)smart_malloc((count + 1) * sizeof(t_mark *));
	mark = start;
	count = 0;
	while (mark)
	{
		arr[count] = mark;
		mark = mark->next;
		count++;
	}
	arr[count] = NULL;
	return (arr);
}

int		print_arg(int arg, char type, char *mark)
{
	if (type == T_REG)
		return (ft_printf("r%-17hhd", arg));
	else if (type == T_DIR)
	{
		if (mark)
			return (ft_printf("%%:%-16s", mark));
		return (ft_printf("%%%-17d", arg));
		
	}
	if (mark)
		return (ft_printf(":%-17s", mark));
	return (ft_printf("%-18d", arg));
}

int		print_arg_chars(int command, int arg, char type)
{
	int		size;
	char	*charg;

	size = g_instr[command].size_dir ? 2 : 4;
	charg = (char *)&arg;
	ft_printf("%20s%-10hhu", "", command);
	if (type == T_REG)
		return (ft_printf("r%-17hhu", arg));
	else if (type == T_DIR)
	{
		while (size--)
			ft_printf("%-4hhu", charg[size]);
		return (ft_printf("  "));
	}
	size = 2;
	while (size--)
		ft_printf("%-4hhu", charg[size]);
	return (ft_printf("  "));
}

void	print_arg_values(int command, int arg, char type)
{

}

void	print_code_info(t_main *main)
{
	t_token     *token;
	t_mark		**marks;
	char		*arg[3];
	int			i;

	marks = get_mark_array(main->mark);
	token = main->token;
	while (token)
	{
		print_marks(token, marks);
		ft_printf("%-5d(%-3d) :        %-10s", token->pos,
		token->len, g_instr[token->instruct].name);
		i = -1;
		while (++i < g_instr[token->instruct].count_args)
			print_arg(token->arg[i], token->type[i], token->marks[i]);
		ft_putchar('\n');
		i = -1;
		while (++i < g_instr[token->instruct].count_args)
			print_arg_chars(token->instruct, token->arg[i], token->type[i]);
		ft_putchar('\n');
		token = token->next;
	}
}
