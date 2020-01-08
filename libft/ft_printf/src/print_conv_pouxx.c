/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv_pouxx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:43:44 by matruman          #+#    #+#             */
/*   Updated: 2019/11/09 15:43:54 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

static char		*get_str(t_format_list *format_list, unsigned long long u,
							int base)
{
	char	*ustr;

	if (format_list->mod.ll || format_list->conv == 'p')
		ustr = ft_itoa_base((u), base);
	else if (format_list->mod.l)
		ustr = ft_itoa_base((unsigned long)u, base);
	else if (format_list->mod.h)
		ustr = ft_itoa_base((unsigned short)u, base);
	else if (format_list->mod.hh)
		ustr = ft_itoa_base((unsigned char)u, base);
	else
		ustr = ft_itoa_base((unsigned int)u, base);
	return (ustr);
}

int				conv_base(char conv)
{
	if (conv == 'b')
		return (2);
	if (conv == 'o')
		return (8);
	if (conv == 'u')
		return (10);
	if (conv == 'p' || conv == 'x' || conv == 'X')
		return (16);
	return (0);
}

int				get_pref(t_format_list *format_list)
{
	if (format_list->flag.hash || format_list->conv == 'p')
	{
		if (format_list->conv == 'x' || format_list->conv == 'X'
			|| format_list->conv == 'p')
			return (2);
		else if (format_list->conv == 'o')
			return (1);
	}
	return (0);
}

void			pouxx_handler(char **ustr, int u, int pf,
											t_format_list *format_list)
{
	if (format_list->precision_flag && !(format_list->flag.zero = 0))
	{
		if (u == 0 && format_list->precision == 0)
			(*ustr)[0] = 0;
		*ustr = add_prefix(*ustr, format_list->precision - ft_strlen(*ustr),
		'0');
	}
	else if (format_list->flag.zero && format_list->flag.minus == 0)
		*ustr = add_prefix(*ustr, format_list->width - pf - ft_strlen(*ustr),
		'0');
	if (pf == 2 && (*ustr = add_prefix(*ustr, 1, 'x')))
		*ustr = add_prefix(*ustr, 1, '0');
	if (pf == 1 && (*ustr)[0] != '0')
		*ustr = add_prefix(*ustr, 1, '0');
	if (format_list->conv == 'X')
		ft_strcap(*ustr);
	if (format_list->flag.zero == 0 && format_list->flag.minus == 0)
		*ustr = add_prefix(*ustr, format_list->width - ft_strlen(*ustr), ' ');
	if (format_list->flag.minus)
		*ustr = add_suffix(*ustr, format_list->width - ft_strlen(*ustr), ' ');
}

int				print_conv_pouxx(t_format_list *format_list, t_buffer *buffer)
{
	unsigned long long	u;
	char				*ustr;
	int					count;
	int					pf;

	count = 0;
	pf = get_pref(format_list);
	u = va_arg(*(format_list->ap), unsigned long long);
	ustr = get_str(format_list, u, conv_base(format_list->conv));
	if ((!u && format_list->conv != 'p' && format_list->conv != 'o')
	|| (format_list->conv == 'o' && format_list->width > (int)ft_strlen(ustr)
	&& format_list->flag.zero && !(format_list->precision_flag)
	&& !(format_list->flag.minus)))
		pf = 0;
	pouxx_handler(&ustr, u, pf, format_list);
	count = pf_buffer_add(buffer, ustr, -1);
	free(ustr);
	return (count);
}
