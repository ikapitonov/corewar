/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:55:27 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/18 14:55:28 by sjamie           ###   ########.fr       */
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

void			ft_t_dir_exec(t_readf content, int fd, int *i, int size)
{
	t_bits	data;
	int		a;

	a = size;
	data = ft_zero_struct();
	while (size >= 0)
	{
		data.str[size] = content.str[*i];
		(*i)++;
		size--;
	}
	if (data.arr[1].a7 == 1 && a == 1)
		data.num -= 65536;
	write(fd, "%", 1);
	ft_putnbr_fd(data.num, fd);
}

void			ft_t_reg_exec(t_readf content, int fd, int *i)
{
	t_bits	data;

	data = ft_zero_struct();
	data.str[0] = content.str[*i];
	(*i)++;
	write(fd, "r", 1);
	ft_putnbr_fd(data.num, fd);
}

void			ft_t_ind_exec(t_readf content, int fd, int *i)
{
	t_bits	data;
	int 	j;
	int		result;

	j = 1;
	data = ft_zero_struct();
	while (j >= 0)
	{
		data.str[j] = content.str[*i];
		(*i)++;
		j--;
	}
	result = data.num;
	if(data.arr[1].a7 == 1)
		result -= 65536;
	ft_putnbr_fd(result, fd);
}

void			read_name(t_readf content, int fd)
{
	int		i = 4;
	char	*str = malloc(sizeof(char) * PROG_NAME_LENGTH + 1);
	char	*start = str;

	while (i <= PROG_NAME_LENGTH + 4)
	{
		*str = content.str[i];
		str++;
		i++;
	}
	*str = '\0';
	str = start;
	write(fd, NAME_CMD_STRING, 5);
	write(fd, "\t\t", 2);
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
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
	int		i = 4 + PROG_NAME_LENGTH + 8;
	char	*str = malloc(sizeof(char) * COMMENT_LENGTH + 1);
	char	*start = str;
	while (i <= COMMENT_LENGTH + PROG_NAME_LENGTH + 4 + 8)
	{
		*str = content.str[i];
		str++;
		i++;
	}
	*str = '\0';
	str = start;
	write(fd, COMMENT_CMD_STRING, 8);
	write(fd, "\t", 1);
	write(fd, str, ft_strlen(str));
	write(fd, "\n\n", 2);
	free(str);
}

void			ft_live_exec(t_readf content, int fd, int *i)
{
	write(fd, "live ", 5);
	(*i)++;
	ft_t_dir_exec(content, fd, i, 3);
	write(fd, "\n", 1);
}

void			ft_ld_exec(t_readf content, int fd, int *i)
{
	t_bits	data;

	data = ft_zero_struct();
	write(fd, "ld ", 3);
	(*i)++;
	data.str[0] = content.str[*i];
	(*i)++;
	if (data.arr->a6 == 0)
		ft_t_dir_exec(content, fd, i, 3);
	else
		ft_t_ind_exec(content, fd, i);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, "\n", 1);
}

void			ft_st_exec(t_readf content, int fd, int *i)
{
	t_bits	data;

	data = ft_zero_struct();
	write(fd, "st ", 3);
	(*i)++;
	data.str[0] = content.str[*i];
	(*i)++;
	ft_t_reg_exec(content, fd, i);
	write(fd, ", ", 2);
	if (data.arr->a5 == 0)
		ft_t_reg_exec(content, fd, i);
	else
		ft_t_ind_exec(content, fd, i);
	write(fd, "\n", 1);
}

void			ft_add_exec(t_readf content, int fd, int *i)
{
	write(fd, "add ", 4);
	(*i)++;
	ft_t_reg_exec(content, fd, i);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, "\n", 1);
}

void			ft_sub_exec(t_readf content, int fd, int *i)
{
	write(fd, "sub ", 4);
	(*i)++;
	ft_t_reg_exec(content, fd, i);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, "\n", 1);
}

void			ft_and_exec(t_readf content, int fd, int *i)
{
	t_bits	data;

	data = ft_zero_struct();
	write(fd, "and ", 4);
	(*i)++;
	data.str[0] = content.str[*i];
	(*i)++;

	if (data.arr->a7 == 0 && data.arr->a6 == 1)
		ft_t_reg_exec(content, fd, i);
	else if (data.arr->a7 == 1 && data.arr->a6 == 1)
		ft_t_ind_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 3);
	write(fd, ", ", 2);
	if (data.arr->a5 == 0 && data.arr->a4 == 1)
		ft_t_reg_exec(content, fd, i);
	else if (data.arr->a5 == 1 && data.arr->a4 == 1)
		ft_t_ind_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 3);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, "\n", 1);
}

void			ft_or_exec(t_readf content, int fd, int *i)
{
	t_bits	data;

	data = ft_zero_struct();
	write(fd, "or ", 3);
	(*i)++;
	data.str[0] = content.str[*i];
	(*i)++;

	if (data.arr->a7 == 0 && data.arr->a6 == 1)
		ft_t_reg_exec(content, fd, i);
	else if (data.arr->a7 == 1 && data.arr->a6 == 1)
		ft_t_ind_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 3);
	write(fd, ", ", 2);
	if (data.arr->a5 == 0 && data.arr->a4 == 1)
		ft_t_reg_exec(content, fd, i);
	else if (data.arr->a5 == 1 && data.arr->a4 == 1)
		ft_t_ind_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 3);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, "\n", 1);
}

void			ft_xor_exec(t_readf content, int fd, int *i)
{
	t_bits	data;

	data = ft_zero_struct();
	write(fd, "xor ", 4);
	(*i)++;
	data.str[0] = content.str[*i];
	(*i)++;

	if (data.arr->a7 == 0 && data.arr->a6 == 1)
		ft_t_reg_exec(content, fd, i);
	else if (data.arr->a7 == 1 && data.arr->a6 == 1)
		ft_t_ind_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 3);
	write(fd, ", ", 2);
	if (data.arr->a5 == 0 && data.arr->a4 == 1)
		ft_t_reg_exec(content, fd, i);
	else if (data.arr->a5 == 1 && data.arr->a4 == 1)
		ft_t_ind_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 3);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, "\n", 1);
}

void			ft_zjmp_exec(t_readf content, int fd, int *i)
{
	write(fd, "zjmp ", 5);
	(*i)++;
	ft_t_dir_exec(content, fd, i, 1);
	write(fd, "\n", 1);
}

void			ft_ldi_exec(t_readf content, int fd, int *i)
{
	t_bits	data;

	data = ft_zero_struct();
	write(fd, "ldi ", 4);
	(*i)++;
	data.str[0] = content.str[*i];
	(*i)++;

	if (data.arr->a7 == 0 && data.arr->a6 == 1)
		ft_t_reg_exec(content, fd, i);
	else if (data.arr->a7 == 1 && data.arr->a6 == 1)
		ft_t_ind_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 1);
	write(fd, ", ", 2);
	if (data.arr->a5 == 0 && data.arr->a4 == 1)
		ft_t_reg_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 1);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, "\n", 1);
}

void			ft_sti_exec(t_readf content, int fd, int *i)
{
	t_bits	data;

	data = ft_zero_struct();
	write(fd, "sti ", 4);
	(*i)++;
	data.str[0] = content.str[*i];
	(*i)++;
	ft_t_reg_exec(content, fd, i);
	write(fd, ", ", 2);
//	printf("%d-%d-%d-%d-%d-%d-%d-%d\n", data.arr[0].a0, data.arr[0].a1, data.arr[0].a2, data.arr[0].a3, data.arr[0].a4, data.arr[0].a5, data.arr[0].a6, data.arr[0].a7);

	if (data.arr->a5 == 0 && data.arr->a4 == 1)
		ft_t_reg_exec(content, fd, i);
	else if (data.arr->a5 == 1 && data.arr->a4 == 1)
		ft_t_ind_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 1);
	write(fd, ", ", 2);
	if (data.arr->a3 == 0 && data.arr->a2 == 1)
		ft_t_reg_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 1);
	write(fd, "\n", 1);
}

void			ft_fork_exec(t_readf content, int fd, int *i)
{
	write(fd, "fork ", 5);
	(*i)++;
	ft_t_dir_exec(content, fd, i, 1);
	write(fd, "\n", 1);
}

void			ft_lld_exec(t_readf content, int fd, int *i)
{
	t_bits	data;

	data = ft_zero_struct();
	write(fd, "lld ", 4);
	(*i)++;
	data.str[0] = content.str[*i];
	(*i)++;
	if (data.arr->a7 == 1 && data.arr->a6 == 1)
		ft_t_ind_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 3);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, "\n", 1);
}

void			ft_lldi_exec(t_readf content, int fd, int *i)
{
	t_bits	data;

	data = ft_zero_struct();
	write(fd, "lldi ", 5);
	(*i)++;
	data.str[0] = content.str[*i];
	(*i)++;

	if (data.arr->a7 == 0 && data.arr->a6 == 1)
		ft_t_reg_exec(content, fd, i);
	else if (data.arr->a7 == 1 && data.arr->a6 == 1)
		ft_t_ind_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 1);
	write(fd, ", ", 2);
	if (data.arr->a5 == 0 && data.arr->a4 == 1)
		ft_t_reg_exec(content, fd, i);
	else
		ft_t_dir_exec(content, fd, i, 1);
	write(fd, ", ", 2);
	ft_t_reg_exec(content, fd, i);
	write(fd, "\n", 1);
}

void			ft_lfork_exec(t_readf content, int fd, int *i)
{
	write(fd, "lfork ", 6);
	(*i)++;
	ft_t_dir_exec(content, fd, i, 1);
	write(fd, "\n", 1);
}

void			ft_aff_exec(t_readf content, int fd, int *i)
{
	write(fd, "aff ", 4);
	(*i)++;
	(*i)++;
	ft_t_reg_exec(content, fd, i);
	write(fd, "\n", 1);
}

int				ft_exec_commands(t_readf content, int fd, int *i)
{
	if(content.str[*i] == 1)
		ft_live_exec(content, fd, i);
	else if(content.str[*i] == 2)
		ft_ld_exec(content, fd, i);
	else if (content.str[*i] == 3)
		ft_st_exec(content, fd, i);
	else if (content.str[*i] == 4)
		ft_add_exec(content, fd, i);
	else if(content.str[*i] == 5)
		ft_sub_exec(content, fd, i);
	else if(content.str[*i] == 6)
		ft_and_exec(content, fd, i);
	else if(content.str[*i] == 7)
		ft_or_exec(content, fd, i);
	else if(content.str[*i] == 8)
		ft_xor_exec(content, fd, i);
	else if (content.str[*i] == 9)
		ft_zjmp_exec(content, fd, i);
	else if(content.str[*i] == 10)
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

void			read_exec_code(t_readf content, int fd)
{
	int	name_len;
	int i;
	t_bits num;

	name_len = read_name_length(content);
	i = 16 + PROG_NAME_LENGTH + COMMENT_LENGTH;
//	printf("i: %d\n", i);
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

void			disassembly(char *filename)
{
	t_readf	content;
	int		ch;
	int		fd;

	if ((ch = open(filename, O_RDONLY)) == -1)
		die(ft_strjoin("Can't read source file ", filename));
	file_get_content(&content, ch);
	if (!content.str || !content.size)
		die("Empty file");
	if (fd = open("disasm.s", O_WRONLY | O_CREAT | O_TRUNC, 0600) == -1)
		die(ft_strjoin("Can't read source file ", "disasm.s"));
	fd = 1;
	read_name(content, fd);
	read_comment(content, fd);
	read_exec_code(content, fd);

	if (close(ch) == -1)
	{
		die(ft_strjoin("Can't close source file ", filename));
	}
}
