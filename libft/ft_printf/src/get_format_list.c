/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:23:18 by matruman          #+#    #+#             */
/*   Updated: 2019/11/06 13:11:17 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

void			zero_format(t_format_list *format_list)
{
	format_list->flag.hash = 0;
	format_list->flag.zero = 0;
	format_list->flag.space = 0;
	format_list->flag.plus = 0;
	format_list->flag.minus = 0;
	format_list->mod.h = 0;
	format_list->mod.hh = 0;
	format_list->mod.l = 0;
	format_list->mod.ll = 0;
	format_list->mod.bl = 0;
	format_list->conv = 0;
	format_list->position = 0;
	format_list->len = 0;
	format_list->width = 0;
	format_list->precision = 0;
	format_list->precision_flag = 0;
	format_list->percent_flag = 0;
}

t_format_list	*format_list_new(const char *format, va_list *ap)
{
	t_format_list	*format_list;

	format_list = (t_format_list *)malloc(sizeof(t_format_list));
	if (!format_list)
		return (NULL);
	format_list->format = format;
	format_list->ap = ap;
	zero_format(format_list);
	format_list->next = NULL;
	return (format_list);
}

t_format_list	*get_format_list(const char *format, va_list *ap)
{
	t_format_list	*format_list_start;
	t_format_list	*format_list;
	int				i;
	int				skip;

	format_list_start = format_list_new(format, ap);
	format_list = format_list_start;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			format_list->position = i;
			skip = get_format(format, format_list);
			if ((format_list->next = format_list_new(format, ap)))
				format_list = format_list->next;
			else
				return (NULL);
			i += skip - 1;
		}
		i++;
	}
	return (format_list_start);
}
