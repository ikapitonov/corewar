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

	if (!g_instr[(int)command].is_code_type)
		return (0);
	count = 0;
	while (count < g_instr[(int)command].count_args)
	{
		if (!types[count] || (types[count] == T_REG_CODE &&
			!(T_REG & g_instr[(int)command].args[count])))
			return (1);
		if (!types[count] || (types[count] == T_DIR_CODE &&
			!(T_DIR & g_instr[(int)command].args[count])))
			return (1);
		if (!types[count] || (types[count] == T_IND_CODE &&
			!(T_IND & g_instr[(int)command].args[count])))
			return (1);
		++count;
	}
	return (0);
}

int		get_arg_size(char command, char type)
{
	if (type == T_REG_CODE)
		return (1);
	if (type == T_DIR_CODE)
		return (g_instr[(int)command].size_dir ? 2 : 4);
	if (type == T_IND_CODE)
		return (2);
	return (0);
}

int		get_arg_types(char command, char *arr, char *area, int pos)
{
	uint8_t types;
	int		ret;
	int		i;

	ret = 0;
	memory_read(area, pos + 1, &types, 1);
	arr[0] = (types & 192) >> 6;
	arr[1] = (types & 48) >> 4;
	arr[2] = (types & 12) >> 2;
	i = -1;
	while (++i < g_instr[(int)command].count_args)
		ret += get_arg_size(command, arr[i]);
	if (g_instr[(int)command].is_code_type)
		ret++;
	else
		ret = g_instr[(int)command].size_dir ? 2 : 4;
	return (ret + 1);
}
