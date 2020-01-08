/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:05:43 by matruman          #+#    #+#             */
/*   Updated: 2019/11/25 20:05:46 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

t_float	*get_params(long double f)
{
	t_float		*fl;

	fl = (t_float *)malloc(sizeof(t_float));
	fl->lflag = 1;
	fl->m = *((unsigned long long *)&f);
	fl->e = *((unsigned short *)&f + 4) & 0x7fff;
	fl->sign = (char)((*((unsigned short *)&f + 4) & 0x8000) >> 15);
	return (fl);
}

t_float	*get_fl(t_format_list *format_list)
{
	double			f;
	long double		lf;

	if (format_list->mod.bl)
	{
		lf = va_arg(*(format_list->ap), long double);
		return (get_params(lf));
	}
	f = va_arg(*(format_list->ap), double);
	return (get_params((long double)f));
}
