/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv_cp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:44:46 by matruman          #+#    #+#             */
/*   Updated: 2019/11/11 14:45:34 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

int		print_conv_cp(t_format_list *format_list, t_buffer *buffer)
{
	char	*str;
	char	c;
	int		count;

	count = 0;
	if (format_list->conv == 'c')
		c = (char)va_arg(*(format_list->ap), int);
	else if ((c = '%') && format_list->percent_flag)
		return (0);
	str = ft_strnew(1);
	str[0] = c;
	if (format_list->flag.zero && format_list->flag.minus == 0)
		str = add_prefix(str, format_list->width - 1, '0');
	else if (format_list->flag.minus == 0)
		str = add_prefix(str, format_list->width - 1, ' ');
	else
		str = add_suffix(str, format_list->width - 1, ' ');
	if (c == 0 && format_list->flag.minus && (count = 1))
		buffer_chadd(buffer, c);
	count += pf_buffer_add(buffer, str, -1);
	if (c == 0 && format_list->flag.minus == 0 && ++count)
		buffer_chadd(buffer, c);
	free(str);
	return (count);
}
