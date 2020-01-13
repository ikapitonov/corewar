/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:54:37 by matruman          #+#    #+#             */
/*   Updated: 2020/01/13 15:54:39 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_arg_types(char *types, char command)
{
	int		count;

	count = 0;
	while (types[count] && count < 4)
		count++;
	if (count != g_instr[command].count_args)
		return (1);
	count = 0;
	while (count < 3)
		if (!types[count] & g_instr[command].args[count])
			return (1);
	return (0);
}

void	get_arg_types(char *typesarr, char *area, int pos)
{
	char types;

	memory_read(area, pos, &types, 1);
	typesarr[0] = types & 3;
	typesarr[1] = (types & 12) >> 2;
	typesarr[2] = (types & 48) >> 4;
}
