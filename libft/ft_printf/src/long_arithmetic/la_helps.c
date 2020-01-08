/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   la_helps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:44:18 by matruman          #+#    #+#             */
/*   Updated: 2019/11/13 20:44:20 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long_arithmetic.h"

t_big_int	*big_int_new(int size)
{
	t_big_int *b_int;

	b_int = (t_big_int *)malloc(sizeof(t_big_int));
	if (!b_int)
		return (NULL);
	b_int->arr = (int *)malloc(size * sizeof(int));
	if (!b_int->arr)
	{
		free(b_int);
		return (NULL);
	}
	b_int->size = size;
	return (b_int);
}

void		big_int_del(t_big_int *b_int)
{
	if (!b_int)
		return ;
	free(b_int->arr);
	free(b_int);
}

void		b_int_copy(t_big_int **dest, t_big_int *src)
{
	int		i;

	*dest = big_int_new(src->size);
	if (!(*dest))
		return ;
	i = 0;
	while (i < (*dest)->size)
	{
		((*dest)->arr)[i] = (src->arr)[i];
		i++;
	}
}

void		b_int_unshift(t_big_int **bb_int)
{
	t_big_int	*new;
	int			i;

	new = big_int_new((*bb_int)->size - 1);
	i = 0;
	while (i < new->size)
	{
		(new->arr)[i] = ((*bb_int)->arr)[i];
		i++;
	}
	big_int_del(*bb_int);
	*bb_int = new;
}

void		b_int_push(t_big_int **bb_int, int push)
{
	t_big_int	*b_int;
	t_big_int	*new;
	int			i;

	b_int = *bb_int;
	new = big_int_new(b_int->size + 1);
	if (!new)
		return ;
	i = 0;
	while (i < b_int->size)
	{
		(new->arr)[i] = (b_int->arr)[i];
		i++;
	}
	(new->arr)[i] = push;
	big_int_del(*bb_int);
	*bb_int = new;
}
