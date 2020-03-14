/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembly.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrowzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 18:35:27 by edrowzee          #+#    #+#             */
/*   Updated: 2020/03/14 18:35:28 by edrowzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_DISASSEMBLY_H
# define COREWAR_DISASSEMBLY_H

typedef struct	s_keybits
{
	unsigned char a0: 1;
	unsigned char a1: 1;
	unsigned char a2: 1;
	unsigned char a3: 1;
	unsigned char a4: 1;
	unsigned char a5: 1;
	unsigned char a6: 1;
	unsigned char a7: 1;
}				t_keybits;

typedef	union	u_bits
{
	char		str[4];
	int			num;
	t_keybits	arr[4];
}				t_bits;

void			ft_t_dir_exec(t_readf content, int fd, int *i, int size);
void			ft_t_reg_exec(t_readf content, int fd, int *i);
void			ft_t_ind_exec(t_readf content, int fd, int *i);
void			ft_live_exec(t_readf content, int fd, int *i);
void			ft_ld_exec(t_readf content, int fd, int *i);
void			ft_st_exec(t_readf content, int fd, int *i);
void			ft_add_exec(t_readf content, int fd, int *i);
void			ft_sub_exec(t_readf content, int fd, int *i);
void			ft_and_exec(t_readf content, int fd, int *i);
void			ft_or_exec(t_readf content, int fd, int *i);
void			ft_xor_exec(t_readf content, int fd, int *i);
void			ft_zjmp_exec(t_readf content, int fd, int *i);
void			ft_ldi_exec(t_readf content, int fd, int *i);
void			ft_sti_exec(t_readf content, int fd, int *i);
void			ft_fork_exec(t_readf content, int fd, int *i);
void			ft_lld_exec(t_readf content, int fd, int *i);
void			ft_lldi_exec(t_readf content, int fd, int *i);
void			ft_lfork_exec(t_readf content, int fd, int *i);
void			ft_aff_exec(t_readf content, int fd, int *i);
t_bits			ft_zero_struct(void);
void			read_name(t_readf content, int fd);
int				read_name_length(t_readf content);
void			read_comment(t_readf content, int fd);

#endif
