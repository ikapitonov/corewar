/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:20:09 by matruman          #+#    #+#             */
/*   Updated: 2019/11/13 13:20:11 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"
#include "long_arithmetic.h"

void	get_str(t_float *fl)
{
	t_big_int	*tmp;
	t_big_int	*tmp1;

	tmp = readll_u(fl->m);
	tmp1 = pow_mult(tmp, 5, 63);
	big_int_del(tmp);
	if (fl->e < 16383)
	{
		tmp = pow_mult(tmp1, 10, 16383 - fl->e);
		big_int_del(tmp1);
		tmp1 = tmp;
	}
	tmp = pow_mult(tmp1, 2, fl->e - 16383);
	fl->str = big_int_tostr(tmp);
	big_int_del(tmp1);
	big_int_del(tmp);
}

void	ft_round(char **intpart, char *fraction, int end)
{
	char	*new;

	while (fraction[end] == '9' && end >= 0 && (fraction[end] = '0'))
		end--;
	if (end >= 0)
		fraction[end] += 1;
	else if ((end = ft_strlen(*intpart) - 1) >= 0)
	{
		while ((*intpart)[end] == '9' && end >= 0)
		{
			(*intpart)[end] = '0';
			end--;
		}
		if (end >= 0)
			(*intpart)[end] += 1;
		else
		{
			new = ft_strnew(ft_strlen(*intpart) + 1);
			new[0] = '1';
			ft_strcpy(new + 1, *intpart);
			free(*intpart);
			*intpart = new;
		}
	}
}

void	get_fstr(t_format_list *format_list, t_float *fl)
{
	int		point;
	int		flen;

	flen = ft_strlen(fl->str);
	point = flen - 63 + ((fl->e < 16383) ? fl->e - 16383 : 0);
	if (flen - point < format_list->precision)
		fl->str = add_suffix(fl->str, format_list->precision -
		(flen - point), '0');
	if (point > 0)
	{
		fl->intpart = ft_strndup(fl->str, point);
		fl->fraction = ft_strndup(fl->str + point, format_list->precision);
		if (fl->str[point + format_list->precision] > '4')
			ft_round(&(fl->intpart), fl->fraction, format_list->precision - 1);
	}
	else
	{
		fl->intpart = ft_strdup("0");
		flen = point + format_list->precision;
		fl->fraction = flen > 0 ? ft_strndup(fl->str, flen) : ft_strdup("");
		fl->fraction = add_prefix(fl->fraction, flen > 0 ?
		-point : format_list->precision, '0');
		if (fl->str[flen > 0 ? flen : 0] > '4')
			ft_round(&(fl->intpart), fl->fraction, format_list->precision - 1);
	}
}

void	float_handler(t_format_list *format_list, t_float *fl)
{
	char	s;

	free(fl->str);
	if (format_list->precision || format_list->flag.hash)
		fl->intpart = add_suffix(fl->intpart, 1, '.');
	fl->str = ft_strjoin(fl->intpart, fl->fraction);
	free(fl->intpart);
	free(fl->fraction);
	s = fl->sign ? '-' : '+';
	if (format_list->flag.zero && format_list->flag.minus == 0)
		fl->str = add_prefix(fl->str, format_list->width -
		(format_list->flag.space || format_list->flag.plus || fl->sign)
		- ft_strlen(fl->str), '0');
	if (fl->sign || format_list->flag.plus)
		fl->str = add_prefix(fl->str, 1, s);
	if (!(format_list->flag.plus) && !fl->sign && format_list->flag.space)
		fl->str = add_prefix(fl->str, 1, ' ');
	if (format_list->flag.zero == 0 && format_list->flag.minus == 0)
		fl->str = add_prefix(fl->str, format_list->width -
		ft_strlen(fl->str), ' ');
	if (format_list->flag.minus)
		fl->str = add_suffix(fl->str, format_list->width -
		ft_strlen(fl->str), ' ');
}

int		print_conv_float(t_format_list *format_list, t_buffer *buffer)
{
	int			count;
	t_float		*fl;

	fl = get_fl(format_list);
	get_str(fl);
	if (!format_list->precision_flag)
		format_list->precision = 6;
	get_fstr(format_list, fl);
	float_handler(format_list, fl);
	count = pf_buffer_add(buffer, fl->str, -1);
	free(fl->str);
	free(fl);
	return (count);
}
