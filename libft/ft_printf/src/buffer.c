/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:05:40 by matruman          #+#    #+#             */
/*   Updated: 2020/01/03 20:05:42 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

void			pf_buffer_init(t_buffer *buffer, int size)
{
	buffer->buff = (char *)malloc(size + 1);
	buffer->used = 0;
	buffer->size = size;
}

static void		buffer_resize(t_buffer *buffer)
{
	buffer->buff = (char *)realloc(buffer->buff, (buffer->size * 3) / 2 + 1);
	buffer->size = (buffer->size * 3) / 2;
}

static int		ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

void			buffer_chadd(t_buffer *buffer, char c)
{
	if (buffer->used == buffer->size)
		buffer_resize(buffer);
	buffer->buff[buffer->used] = c;
	buffer->used++;
}

int				pf_buffer_add(t_buffer *buffer, const char *str, size_t size)
{
	size_t	s;
	size_t	min;

	s = -1;
	min = ft_min(ft_strlen(str), size);
	if (min < buffer->size - buffer->used && (size <
	buffer->size - buffer->used || size == s))
	{
		ft_fstrncpy(buffer->buff + buffer->used, str, size);
		buffer->used += min;
		return (min);
	}
	buffer_resize(buffer);
	return (pf_buffer_add(buffer, str, size));
}
