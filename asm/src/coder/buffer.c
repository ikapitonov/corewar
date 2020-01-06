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

#include "../../includes/asm.h"

void    *sm_realloc(void *ptr, size_t size)
{
	void    *new;

	if (!(new = realloc(ptr, size)))
		die("Cannot allocate memory in realloc");
	return (new);
}

void	buffer_init(t_buffer *buffer, int size)
{
	buffer->buff = (char *)smart_malloc(size);
	buffer->used = 0;
	buffer->size = size;
}

void	buffer_resize(t_buffer *buffer)
{
	buffer->buff = (char *)sm_realloc(buffer->buff, (buffer->size * 3) / 2);
	buffer->size = (buffer->size * 3) / 2;
}

void	buffer_add(t_buffer	*buffer, char *str, int size)
{
	if (size < buffer->size - buffer->used)
	{
		ft_memcpy(buffer->buff + buffer->used, str, size);
		buffer->used += size;
		return ;
	}
	else
	{
		buffer_resize(buffer);
		buffer_add(buffer, str, size);
	}
}