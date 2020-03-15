/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrowzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:55:27 by edrowzee          #+#    #+#             */
/*   Updated: 2020/01/18 14:55:28 by edrowzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"
#include "disassembly.h"

t_bits			ft_zero_struct(void)
{
	t_bits result;

	result.str[0] = 0;
	result.str[1] = 0;
	result.str[2] = 0;
	result.str[3] = 0;
	return (result);
}

void			read_name(t_readf content, int fd)
{
	int		i;
	char	*str;
	char	*start;

	i = 4;
	str = malloc(sizeof(char) * PROG_NAME_LENGTH + 10);
	start = str;
	while (i <= PROG_NAME_LENGTH + 4)
	{
		*str = content.str[i];
		str++;
		i++;
	}
	*str = '\0';
	str = start;
	write(fd, NAME_CMD_STRING, 5);
	write(fd, "\t\t\"", 3);
	write(fd, str, ft_strlen(str));
	write(fd, "\"\n", 2);
	free(str);
}

int				read_name_length(t_readf content)
{
	t_bits num;

	num.str[0] = content.str[8 + PROG_NAME_LENGTH + 3];
	num.str[1] = content.str[8 + PROG_NAME_LENGTH + 2];
	num.str[2] = content.str[8 + PROG_NAME_LENGTH + 1];
	num.str[3] = content.str[8 + PROG_NAME_LENGTH + 0];
	if (num.num > CHAMP_MAX_SIZE)
		die("Champ code size more than CHAMP_MAX_SIZE");
	return (num.num);
}

void			read_comment(t_readf content, int fd)
{
	int		i;
	char	*str;
	char	*start;

	i = 4 + PROG_NAME_LENGTH + 8;
	str = malloc(sizeof(char) * COMMENT_LENGTH + 10);
	start = str;
	while (i <= COMMENT_LENGTH + PROG_NAME_LENGTH + 4 + 8)
	{
		*str = content.str[i];
		str++;
		i++;
	}
	*str = '\0';
	str = start;
	write(fd, COMMENT_CMD_STRING, 8);
	write(fd, "\t\"", 2);
	write(fd, str, ft_strlen(str));
	write(fd, "\"\n\n", 3);
	free(str);
}
