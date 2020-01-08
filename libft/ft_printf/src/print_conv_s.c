/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:04:20 by matruman          #+#    #+#             */
/*   Updated: 2019/11/11 18:04:30 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

char	*ft_strndup(char *str, size_t n)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(str);
	len = len < n ? len : n;
	copy = ft_strnew(len);
	if (!copy)
		return (NULL);
	ft_strncpy(copy, str, len);
	return (copy);
}

int		print_conv_s(t_format_list *format_list, t_buffer *buffer)
{
	char	*arg;
	char	*str;
	int		count;

	arg = va_arg(*(format_list->ap), char *);
	if (arg)
		str = ft_strndup(arg, format_list->precision_flag ?
		format_list->precision : ft_strlen(arg));
	else
		str = ft_strndup("(null)", format_list->precision_flag ?
		format_list->precision : 6);
	if (format_list->flag.minus == 0)
		str = add_prefix(str, format_list->width - ft_strlen(str), ' ');
	else
		str = add_suffix(str, format_list->width - ft_strlen(str), ' ');
	count = pf_buffer_add(buffer, str, -1);
	free(str);
	return (count);
}
