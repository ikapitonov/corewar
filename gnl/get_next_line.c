/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:36:10 by matruman          #+#    #+#             */
/*   Updated: 2019/10/06 15:35:20 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*ft_listnew(int fd)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = (void *)ft_strnew(0);
	list->next = NULL;
	if (!(list->content))
	{
		free(list);
		return (NULL);
	}
	list->content_size = fd;
	return (list);
}

static int		get_fdlist(t_list **plist, int fd)
{
	t_list	*list;

	list = *plist;
	while ((int)list->content_size != fd && list->next)
		list = list->next;
	if (!list->next && (int)list->content_size != fd)
	{
		list->next = ft_listnew(fd);
		if (list->next)
			list = list->next;
		else
			return (-1);
	}
	*plist = list;
	return (0);
}

static int		save_line(char *str, char **line)
{
	char	*end;

	if ((end = ft_strchr(str, '\n')))
	{
		if (!(*line = ft_strnew((size_t)(end - str))))
			return (1);
		ft_strncpy(*line, str, (size_t)(end - str));
		ft_memmove(str, end + 1, ft_strlen(str) - (size_t)(end - str));
	}
	else
	{
		if (!(*line = ft_strnew(ft_strlen(str) + 1)))
			return (1);
		ft_strcpy(*line, str);
		ft_bzero(str, ft_strlen(str));
	}
	return (0);
}

static int		gnl_fn(t_list *list, char **line, char *tmp, char *tmp1)
{
	int		count;
	char	*str;

	str = (char *)(list->content);
	if (ft_strchr(str, '\n'))
		if (save_line(str, line) || 1)
			return (1);
	tmp = ft_strnew(BUFF_SIZE);
	count = 0;
	while (read((int)list->content_size, tmp, BUFF_SIZE))
	{
		count++;
		if (!(tmp1 = ft_strjoin(str, tmp)))
			return (-1);
		ft_strdel(&str);
		str = tmp1;
		if (ft_strchr(tmp, '\n'))
			break ;
		ft_bzero(tmp, BUFF_SIZE);
	}
	save_line(str, line);
	ft_strdel(&tmp);
	list->content = (void *)str;
	return (count || **line);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*main_list = NULL;
	t_list			*list;
	int				ans;

	if (fd < 0 || read(fd, &ans, 0) < 0)
		if ((line && !(*line = NULL)) || 1)
			return (-1);
	if (!main_list)
		main_list = ft_listnew(fd);
	list = main_list;
	if (get_fdlist(&list, fd))
		return (-1);
	if ((ans = gnl_fn(list, line, NULL, NULL)) == 0)
	{
		ft_lstcutelem(list, &main_list);
		ft_strdel(line);
		*line = NULL;
		return (0);
	}
	if (ans == -1 && !(*line = NULL))
		return (-1);
	return (1);
}
