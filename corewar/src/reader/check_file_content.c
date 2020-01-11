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

void	rev_endian(void *val, int size)
{
	char	*p;
	char	tmp;
	int		i;

	p = (char *)val;
	i = 0;
	while (i < size / 2)
	{
		tmp = p[size - i - 1];
		p[size - i - 1] = p[i];
		p[i] = tmp;
		i++; 
	}
}

void			check_magic_header(char *str)
{
	return ;
}

static	void	check_code_size(t_main *main, char *str)
{
	char	buff[CODE_SIZE_FILE + 1];
	int		i;
	int		j;

	i = 0;
	j = 0;
	str += START_NAME + PROG_NAME_LENGTH + NULL_SIZE;
	printf("%d\n", (int) str);
	while (i < CODE_SIZE_FILE)
	{
		if (str[i])
		{
			buff[j++] = str[i];
		//	ft_putnbr(buff[j- 1]);
		}
		++i;
	}
	buff[j] = 0;
	j = 0;
	while (buff[j])
	{
	//	printf("%d\n", buff[j]);
		ft_putnbr(buff[j]);
		printf("\n");
		++j;
	}
	// printf("%d\n", ft_atoi(buff));
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

void			check_file_content(t_main *main, t_read *reader)
{
	char	*str;

	str = reader->str;
	check_magic_header(str);
	get_name_and_comment(main, str);
	check_code_size(main, str);
}
