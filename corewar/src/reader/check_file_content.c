/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 21:54:10 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/11 21:54:11 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static	void	check_magic_header(char *str)
{
	int32_t	res;

	memory_read(str, 0, &res, 4);
	rev_endian(&res, 4);
	if (res != COREWAR_EXEC_MAGIC)
		die("Invalid constant \"COREWAR_EXEC_MAGIC\"");
}

static	void	check_code_size(t_main *main, char *str, int size)
{
	int32_t	res;
	int		tmp;

	str += START_NAME + PROG_NAME_LENGTH + NULL_SIZE;
	memory_read(str, 0, &res, 4);
	rev_endian(&res, 4);
	main->player[main->players].code_size = res;
	tmp = size - START_COMMENT - COMMENT_LENGTH - NULL_SIZE;
	if (tmp != res)
		die("Invalid constant \"code size\"");
}

static	void	get_name_and_comment(t_main *main, char *str)
{
	char	name[PROG_NAME_LENGTH + 1];
	char	comment[COMMENT_LENGTH + 1];

	ft_strncpy(name, str + START_NAME, PROG_NAME_LENGTH);
	ft_strncpy(comment, str + START_COMMENT, COMMENT_LENGTH);
	name[PROG_NAME_LENGTH] = 0;
	comment[COMMENT_LENGTH] = 0;
	main->player[main->players].name = ft_strdup(name);
	main->player[main->players].comment = ft_strdup(comment);
}

static	void	check_null(char *str)
{
	int		i;

	i = 0;
	while (i < NULL_SIZE)
	{
		if (str[i])
		{
			die("Invalid constant \"NULL\"");
		}
		++i;
	}
}

void			check_file_content(t_main *main, t_read *reader)
{
	char	*str;

	str = reader->str;
	check_magic_header(str);
	get_name_and_comment(main, str);
	check_code_size(main, str, reader->size);
	check_null(str + START_NAME + PROG_NAME_LENGTH);
	check_null(str + START_COMMENT + COMMENT_LENGTH);
}
