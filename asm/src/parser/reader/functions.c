/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 19:44:17 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/03 19:44:18 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/asm.h"	

int				int_strchr(char *str)
{
	int		i;

	i = 0;
	while (str[i] && ft_isalpha(str[i]))
		++i;
	return (str[i] && is_empty(str[i]) ? i : 0);
}

int				is_comment(int c)
{
	return (c == COMMENT_CHAR || c == ALT_COMMENT_CHAR ? 1 : 0);
}

int				is_empty(int c)
{
	return (c == '\t' || c == ' ' || (c >= 9 && c <= 13) ? 1 : 0);
}

int				args_exception(int c)
{
	return (c != SEPARATOR_CHAR && c != COMMENT_CHAR &&
			c != ALT_COMMENT_CHAR && c && !is_empty(c) ? 1 : 0);
}

void			trim_str(char *str, int *i)
{
	while (is_empty(str[*i]))
	{
		*i += 1;
	}
}
