/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:27:43 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/11 15:27:44 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int				is_number(int count_args, char *params[], int i)
{
	return (++i == count_args || !ft_isdigit(params[i][0]) ? 0 : 1);
}

int				valid_number(char *str)
{
	int		number;

	if ((number = ft_atoi(str)) <= 0)
		help();
	return (number);
}

void			valid_filename(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 5)
		help();
	if (ft_strcmp(filename + (len - 4), ".cor"))
		help();
}
