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

void			disassembly(char *filename)
{
	t_readf	content;
	int		ch;

	if ((ch = open(filename, O_RDONLY)) == -1)
		die(ft_strjoin("Can't read source file ", filename));
	file_get_content(&content, ch);
	if (!content.str || !content.size)
		die("Empty file");

	printf("%zu\n", content.size);
	// content.str - данные
	// content.size - длина

	if (close(ch) == -1)
	{
		die(ft_strjoin("Can't close source file ", filename));
	}
}
