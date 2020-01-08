/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_helps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:26:52 by matruman          #+#    #+#             */
/*   Updated: 2019/11/06 13:34:11 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

int		isconv(char c)
{
	if (c == 'd' || c == 'i' || c == 'b' || c == 'o' || c == 'u' || c == 'x' ||
		c == 'X' || c == 'c' || c == 's' || c == 'p' || c == 'f' || c == '%')
		return (1);
	else
		return (0);
}

int		isflag(char c)
{
	if (c == '#' || c == '0' || c == ' ' || c == '+' || c == '-')
		return (1);
	else
		return (0);
}

int		ismod(char c)
{
	if (c == 'l' || c == 'h' || c == 'L')
		return (1);
	else
		return (0);
}
