/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 15:59:50 by matruman          #+#    #+#             */
/*   Updated: 2020/01/04 15:59:51 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

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

void	set_header(t_main *main)
{
	t_header	header;

	header.magic = COREWAR_EXEC_MAGIC;
	rev_endian(&header.magic, 4);
	header.null = 0;
	header.prog_size = 0;
	ft_bzero(header.prog_name, PROG_NAME_LENGTH);
	ft_bzero(header.comment, COMMENT_LENGTH);
	ft_strcpy(header.prog_name, main->name);
	ft_strcpy(header.comment, main->comment);
	buffer_add(&main->buffer, (char *)&header.magic, 4);
	buffer_add(&main->buffer, header.prog_name, PROG_NAME_LENGTH);
	buffer_add(&main->buffer, (char *)&header.null, 4);
	buffer_add(&main->buffer, (char *)&header.prog_size, 4);
	buffer_add(&main->buffer, header.comment, COMMENT_LENGTH);
	buffer_add(&main->buffer, (char *)&header.null, 4);
}

void	set_prog_size(t_main *main, int size)
{
	int		set;

	set = size;
	rev_endian(&set, 4);
	*(int *)(&main->buffer.buff[PROG_NAME_LENGTH + 8]) = set;
}

void	write_to_file(t_main *main)
{
	int		fd;

	fd = open(main->filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd < 0)
		die("Cannot open file for writing");
	ft_printf("Writing output to file %s\n", main->filename);
	write(fd, main->buffer.buff, main->buffer.used);
}
