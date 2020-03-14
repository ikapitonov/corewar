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

void			ft_exec_commands_2(t_readf content, int fd, int *i)
{
	if (content.str[*i] == 9)
		ft_zjmp_exec(content, fd, i);
	else if (content.str[*i] == 10)
		ft_ldi_exec(content, fd, i);
	else if (content.str[*i] == 11)
		ft_sti_exec(content, fd, i);
	else if (content.str[*i] == 12)
		ft_fork_exec(content, fd, i);
	else if (content.str[*i] == 13)
		ft_lld_exec(content, fd, i);
	else if (content.str[*i] == 14)
		ft_lldi_exec(content, fd, i);
	else if (content.str[*i] == 15)
		ft_lfork_exec(content, fd, i);
	else if (content.str[*i] == 16)
		ft_aff_exec(content, fd, i);
	else
		die("Error with bytes!");
}

void			ft_exec_commands(t_readf content, int fd, int *i)
{
	if (content.str[*i] == 1)
		ft_live_exec(content, fd, i);
	else if (content.str[*i] == 2)
		ft_ld_exec(content, fd, i);
	else if (content.str[*i] == 3)
		ft_st_exec(content, fd, i);
	else if (content.str[*i] == 4)
		ft_add_exec(content, fd, i);
	else if (content.str[*i] == 5)
		ft_sub_exec(content, fd, i);
	else if (content.str[*i] == 6)
		ft_and_exec(content, fd, i);
	else if (content.str[*i] == 7)
		ft_or_exec(content, fd, i);
	else if (content.str[*i] == 8)
		ft_xor_exec(content, fd, i);
	else
		ft_exec_commands_2(content, fd, i);
}

void			read_exec_code(t_readf content, int fd)
{
	int		name_len;
	int		i;
	t_bits	num;

	name_len = read_name_length(content);
	i = 16 + PROG_NAME_LENGTH + COMMENT_LENGTH;
	while (i < 16 + PROG_NAME_LENGTH + COMMENT_LENGTH + name_len)
	{
		num = ft_zero_struct();
		num.str[0] = content.str[i];
		if (num.num >= 1 && num.num <= 16)
		{
			ft_exec_commands(content, fd, &i);
			continue ;
		}
		else
			die("Error, while read bytes");
		i++;
	}
}

char			*dis_filename(char *filename)
{
	char	*result;
	size_t	len;
	int		i;

	len = ft_strlen(filename);
	result = smart_malloc(len);
	len -= 3;
	ft_strncpy(result, filename, len);
	i = 0;
	result[len + i++] = 's';
	result[len + i++] = 0;
	return (result);
}

void			disassembly(char *filename)
{
	t_readf	content;
	int		ch;
	int		fd;
	char	*res;

	res = dis_filename(filename);
	if ((ch = open(filename, O_RDONLY)) == -1)
		die(ft_strjoin("Can't read source file ", filename));
	file_get_content(&content, ch);
	if (!content.str || !content.size)
		die("Empty file");
	if ((fd = open(res, O_WRONLY | O_CREAT | O_TRUNC, 0600)) == -1)
		die(ft_strjoin("Can't read source file ", res));
	free(res);
	read_name(content, fd);
	read_comment(content, fd);
	read_exec_code(content, fd);
	if (close(ch) == -1)
	{
		die(ft_strjoin("Can't close source file ", filename));
	}
}
