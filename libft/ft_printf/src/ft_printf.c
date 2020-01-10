/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:19:24 by matruman          #+#    #+#             */
/*   Updated: 2019/11/03 18:41:27 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	t_format_list	*format_list;
	t_buffer		buffer;
	int				count;

	va_start(ap, format);
	pf_buffer_init(&buffer, 32);
	format_list = get_format_list(format, &ap);
	count = print_format_list(format_list, &buffer);
	va_end(ap);
	free_format_list(format_list);
	write(1, buffer.buff, buffer.used);
	free(buffer.buff);
	return (count);
}

int		ft_fprintf(int fd, const char *format, ...)
{
	va_list			ap;
	t_format_list	*format_list;
	t_buffer		buffer;
	int				count;

	va_start(ap, format);
	pf_buffer_init(&buffer, 32);
	format_list = get_format_list(format, &ap);
	count = print_format_list(format_list, &buffer);
	va_end(ap);
	free_format_list(format_list);
	write(fd, buffer.buff, buffer.used);
	free(buffer.buff);
	return (count);
}

char	*ft_sprintf(const char *format, ...)
{
	va_list			ap;
	t_format_list	*format_list;
	t_buffer		buffer;
	int				count;

	va_start(ap, format);
	pf_buffer_init(&buffer, 32);
	format_list = get_format_list(format, &ap);
	count = print_format_list(format_list, &buffer);
	va_end(ap);
	free_format_list(format_list);
	buffer.buff[buffer.used] = 0;
	return (buffer.buff);
}
