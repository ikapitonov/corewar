/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_get_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:18:54 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/11 17:18:56 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>
#include <unistd.h>

static	char	*join_exec(t_joinf *list, size_t length)
{
	t_joinf	*tmp;
	char	*content;
	size_t	all;

	if (!length)
		return (NULL);
	all = 0;
	content = (char*)smart_malloc(length + 1);
	while (list)
	{
		tmp = list->next;
		ft_memcpy(content + all, list->str, list->length);
		all += list->length;
		free(list->str);
		free(list);
		list = tmp;
	}
	content[length] = 0;
	return (content);
}

static	char	*my_strdup(const char *s1, size_t size)
{
	char	*res;
	size_t	i;

	res = (char *)malloc(size);
	if (res)
	{
		i = 0;
		while (i < size)
		{
			res[i] = s1[i];
			i++;
		}
		return (res);
	}
	else
		return (NULL);
}

static	void	*new_join(char *str, size_t len)
{
	t_joinf	*new;

	new = (t_joinf*)smart_malloc(sizeof(t_joinf));
	new->str = my_strdup(str, len);
	new->length = len;
	new->next = NULL;
	return ((void*)new);
}

void			file_get_content(t_readf *new, int ch)
{
	t_joinf	*list;
	t_joinf	*last;
	char	reader[1000 + 1];
	int		tmp;
	size_t	len;

	list = NULL;
	len = 0;
	while ((tmp = read(ch, reader, 1000)))
	{
		reader[tmp] = 0;
		if (!list)
		{
			list = new_join(reader, tmp);
			last = list;
		}
		else
		{
			last->next = new_join(reader, tmp);
			last = last->next;
		}
		len += last->length;
	}
	new->str = join_exec(list, len);
	new->size = len;
}
