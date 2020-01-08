/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithmetic.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:41:31 by matruman          #+#    #+#             */
/*   Updated: 2019/11/13 19:43:56 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONG_ARITHMETIC_H
# define LONG_ARITHMETIC_H

# include <stdlib.h>
# include "libft.h"

# define BASE 1000000000

typedef struct		s_big_int
{
	int				sign;
	int				*arr;
	int				size;
}					t_big_int;

t_big_int			*big_int_new(int size);
void				big_int_del(t_big_int *b_int);
void				b_int_copy(t_big_int **dest, t_big_int *src);
void				b_int_push(t_big_int **bb_int, int push);
void				b_int_unshift(t_big_int **bb_int);
t_big_int			*readll_u(unsigned long long n);
char				*big_int_tostr(t_big_int *b_int);
t_big_int			*b_int_mult(t_big_int *b_int, int m);
t_big_int			*b_int_div(t_big_int *b_int, int d);
t_big_int			*b_int_add(t_big_int *a, t_big_int *b);
t_big_int			*pow_mult(t_big_int *big, int b, int pow);
t_big_int			*pow_div(t_big_int *big, int b, int pow);

#endif
