/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:57:51 by matruman          #+#    #+#             */
/*   Updated: 2019/11/09 17:21:23 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

static char		*get_str(t_format_list *format_list, long long d)
{
	char	*dstr;

	if (format_list->mod.ll)
		dstr = ft_itoa_base(get_unsigned(d), 10);
	else if (format_list->mod.l)
		dstr = ft_itoa_base(get_unsigned((long)d), 10);
	else if (format_list->mod.h)
		dstr = ft_itoa_base(get_unsigned((short)d), 10);
	else if (format_list->mod.hh)
		dstr = ft_itoa_base(get_unsigned((signed char)d), 10);
	else
		dstr = ft_itoa_base(get_unsigned((int)d), 10);
	return (dstr);
}

char			get_sign(t_format_list *format_list, long long d)
{
	char	sign;

	if (format_list->mod.ll)
		sign = (d < 0) ? '-' : '+';
	else if (format_list->mod.l)
		sign = ((long)d < 0) ? '-' : '+';
	else if (format_list->mod.h)
		sign = ((short)d < 0) ? '-' : '+';
	else if (format_list->mod.hh)
		sign = ((signed char)d < 0) ? '-' : '+';
	else
		sign = ((int)d < 0) ? '-' : '+';
	return (sign);
}

void			di_handler(char **dstr, int d, int sign,
										t_format_list *format_list)
{
	if (format_list->precision_flag && !(format_list->flag.zero = 0))
	{
		if (d == 0 && format_list->precision == 0)
			(*dstr)[0] = 0;
		*dstr = add_prefix(*dstr,
		format_list->precision - ft_strlen(*dstr), '0');
	}
	else if (format_list->flag.zero && format_list->flag.minus == 0)
		*dstr = add_prefix(*dstr, format_list->width - (format_list->flag.space
		|| format_list->flag.plus || (sign == '-')) - ft_strlen(*dstr), '0');
	if (sign == '-' || format_list->flag.plus)
		*dstr = add_prefix(*dstr, 1, sign);
	if (!(format_list->flag.plus) && sign == '+' && format_list->flag.space)
		*dstr = add_prefix(*dstr, 1, ' ');
	if (format_list->flag.zero == 0 && format_list->flag.minus == 0)
		*dstr = add_prefix(*dstr, format_list->width - ft_strlen(*dstr), ' ');
	if (format_list->flag.minus)
		*dstr = add_suffix(*dstr, format_list->width - ft_strlen(*dstr), ' ');
}

int				print_conv_di(t_format_list *format_list, t_buffer *buffer)
{
	long long	d;
	int			count;
	char		*dstr;
	char		sign;

	d = va_arg(*(format_list->ap), long long);
	sign = get_sign(format_list, d);
	dstr = get_str(format_list, d);
	di_handler(&dstr, d, sign, format_list);
	count = pf_buffer_add(buffer, dstr, -1);
	free(dstr);
	return (count);
}
