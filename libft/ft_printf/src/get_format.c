/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:25:05 by matruman          #+#    #+#             */
/*   Updated: 2019/11/06 14:11:12 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

int		get_flags(const char *format, t_format_list *format_list)
{
	int		i;

	i = format_list->position + 1;
	while (isflag(format[i]))
	{
		if (format[i] == '#')
			format_list->flag.hash = 1;
		else if (format[i] == '0')
			format_list->flag.zero = 1;
		else if (format[i] == ' ')
			format_list->flag.space = 1;
		else if (format[i] == '+')
			format_list->flag.plus = 1;
		else if (format[i] == '-')
			format_list->flag.minus = 1;
		i++;
	}
	return (i);
}

int		get_width_precision(int start, const char *format,
											t_format_list *format_list)
{
	format_list->width = ft_atoi(format + start);
	while (ft_isdigit(format[start]))
		start++;
	if (format[start] == '.')
	{
		start++;
		format_list->precision = ft_atoi(format + start);
		format_list->precision_flag = 1;
		while (ft_isdigit(format[start]))
			start++;
	}
	return (start);
}

int		get_mod(int start, const char *format, t_format_list *format_list)
{
	while (ismod(format[start]))
	{
		if (format[start] == 'h' && !(format_list->mod.hh))
		{
			format_list->mod.h = 1;
			if (format[start + 1] == 'h' && !(format_list->mod.h = 0))
				format_list->mod.hh = 1;
		}
		if (format[start] == 'l' && !(format_list->mod.ll))
		{
			format_list->mod.l = 1;
			if (format[start + 1] == 'l' && !(format_list->mod.l = 0))
				format_list->mod.ll = 1;
		}
		if (format[start] == 'L')
			format_list->mod.bl = 1;
		start++;
	}
	return (start);
}

int		get_conv(int start, const char *format, t_format_list *format_list)
{
	if (isconv(format[start]))
	{
		format_list->conv = format[start];
		return (1);
	}
	return (0);
}

int		get_format(const char *format, t_format_list *format_list)
{
	int		start;

	start = get_flags(format, format_list);
	start = get_width_precision(start, format, format_list);
	start = get_mod(start, format, format_list);
	if (get_conv(start, format, format_list))
	{
		format_list->len = start - format_list->position + 1;
		return (format_list->len);
	}
	else
	{
		format_list->conv = '%';
		format_list->percent_flag = 1;
		format_list->len = 1;
		return (1);
	}
}
