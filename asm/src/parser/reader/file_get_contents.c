/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_get_contents.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:18:53 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/04 17:18:54 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/asm.h"

static	char	*join_exec(t_join *list, size_t length)
{
	t_join	*tmp;
	char	*content;
	size_t	all;

	if (!length)
		return (NULL);
	all = 0;
	content = (char*)smart_malloc(length + 1);
	while (list)
	{
		tmp = list->next;
		ft_strncpy(content + all, list->str, list->length);
		all += list->length;
		free(list->str);
		free(list);
		list = tmp;
	}
	content[length] = 0;
	return (content);
}

static	void	*new_join(char *str)
{
	t_join	*new;

	new = (t_join*)smart_malloc(sizeof(t_join));
	new->str = ft_strdup(str);
	new->length = ft_strlen(str);
	new->next = NULL;
	return ((void*)new);
}

char            *file_get_contents(int ch)
{
	t_join	*list;
	t_join	*last;
	char	reader[BUFF_SIZE + 1];
	int		tmp;
	size_t	len;

	list = NULL;
	len = 0;
	while ((tmp = read(ch, reader, BUFF_SIZE)))
	{
		reader[tmp] = 0;
		if (!list)
		{
			list = new_join(reader);
			last = list;
		}
		else
		{
			last->next = new_join(reader);
			last = last->next;
		}
		len += last->length;
	}
	return (join_exec(list, len));
}
