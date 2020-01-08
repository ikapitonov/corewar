/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_helps1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:58:28 by matruman          #+#    #+#             */
/*   Updated: 2019/11/25 19:58:31 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

char	*add_prefix(char *str, int count, char c)
{
	char	*zero_str;
	char	*res;

	if (count <= 0)
		return (str);
	zero_str = ft_strnew(count);
	ft_memset(zero_str, c, count);
	res = ft_strjoin(zero_str, str);
	free(str);
	free(zero_str);
	return (res);
}

char	*add_suffix(char *str, int count, char c)
{
	char	*zero_str;
	char	*res;

	if (count <= 0)
		return (str);
	zero_str = ft_strnew(count);
	ft_memset(zero_str, c, count);
	res = ft_strjoin(str, zero_str);
	free(str);
	free(zero_str);
	return (res);
}

void	ft_strcap(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

void	free_format_list(t_format_list *list)
{
	t_format_list	*next;

	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
}
