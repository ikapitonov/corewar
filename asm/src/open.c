/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 22:40:32 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/05 22:40:34 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char			*get_filename(char *filename)
{
	char	*str;
	char	*res;
	size_t	len;
	size_t	tmp;

	str = ft_strtrim(filename);
	len = ft_strlen(filename);
	tmp = len - 1;
	res = (char*)smart_malloc(len + 3);
	ft_strncpy(res, str, tmp);
	res[tmp++] = 'c';
	res[tmp++] = 'o';
	res[tmp++] = 'r';
	res[tmp++] = 0;
	free(str);
	return (res);
}

static	int		check_flag(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && str[i + 1] == 'a' &&
			(is_empty(str[i + 2]) || !str[i + 2]))
		{
			return (1);
		}
		++i;
	}
	return (0);
}

static	void	check_filename(char *filename)
{
	char	*str;
	size_t	i;

	str = ft_strtrim(filename);
	i = ft_strlen(str);
	if (i < 3 || str[i - 1] != 's' || str[i - 2] != '.')
	{
		die(ft_strjoin("Not valid filename ", filename));
	}
	free(str);
}

int				check_args(int ac, char *av[])
{
	if (ac > 2)
	{
		if (check_flag(av[1]))
		{
			check_filename(av[2]);
			return (2);
		}
		if (check_flag(av[2]))
		{
			check_filename(av[1]);
			return (1);
		}
		die("Flag name is \"-a\"");
	}
	check_filename(av[1]);
	return (1);
}
