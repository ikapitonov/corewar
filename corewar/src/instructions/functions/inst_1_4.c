/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_1_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:40:34 by matruman          #+#    #+#             */
/*   Updated: 2020/01/11 21:19:43 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    live(t_main *main, t_cursor *cursor, char *area)
{
	memory_read(area, cursor->pos + 1, cursor->registers[0], 4);
}

void	ld(t_main *main, t_cursor *cursor, char *area)
{
	char	types;
}
