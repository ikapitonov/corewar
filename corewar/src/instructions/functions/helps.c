/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:09:09 by matruman          #+#    #+#             */
/*   Updated: 2020/03/16 16:09:13 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		bop_op(int a, int b, char op)
{
	if (op == '&')
		return (a & b);
	if (op == '|')
		return (a | b);
	if (op == '^')
		return (a ^ b);
	return (0);
}

void	bop_reg(t_cursor *c, char *area, uint8_t *m, char op)
{
	if (c->types[1] == T_REG_CODE)
	{
		if (m[1] > 16 || m[2] > 16 || !m[1] || !m[2])
			return ;
		c->reg[m[2] - 1] = bop_op(c->reg[m[0] - 1], c->reg[m[1] - 1], op);
		c->carry = !c->reg[m[2] - 1];
		return ;
	}
	if (c->types[1] == T_DIR_CODE)
	{
		if (m[5] > 16 || !m[5])
			return ;
		c->reg[m[5] - 1] = bop_op(*(int *)(m + 1), c->reg[m[0] - 1], op);
		c->carry = !c->reg[m[5] - 1];
		return ;
	}
	if (m[3] > 16 || !m[3])
		return ;
	rev_endian(m + 1, 2);
	memory_read(area, c->pos + *(short *)(m + 1) % IDX_MOD, m + 4, 4);
	c->reg[m[3] - 1] = bop_op(*(int *)(m + 4), c->reg[m[0] - 1], op);
	c->carry = !c->reg[m[3] - 1];
}

void	bop_dir(t_cursor *c, char *area, uint8_t *m, char op)
{
	if (c->types[1] == T_REG_CODE)
	{
		if (m[4] > 16 || m[5] > 16 || !m[4] || !m[5])
			return ;
		c->reg[m[5] - 1] = bop_op(*(int *)(m), c->reg[m[4] - 1], op);
		c->carry = !c->reg[m[5] - 1];
		return ;
	}
	if (c->types[1] == T_DIR_CODE)
	{
		if (m[8] > 16 || !m[8])
			return ;
		c->reg[m[8] - 1] = bop_op(*(int *)(m), *(int *)(m + 4), op);
		c->carry = !c->reg[m[8] - 1];
		return ;
	}
	if (m[6] > 16 || !m[6])
		return ;
	rev_endian(m + 4, 2);
	memory_read(area, c->pos + *(short *)(m + 4) % IDX_MOD, m + 7, 4);
	c->reg[m[6] - 1] = bop_op(*(int *)(m), *(int *)(m + 7), op);
	c->carry = !c->reg[m[6] - 1];
}

void	bop_ind(t_cursor *c, char *area, uint8_t *m, char op)
{
	if (c->types[1] == T_REG_CODE)
	{
		if (m[2] > 16 || m[3] > 16 || !m[2] || !m[3])
			return ;
		c->reg[m[3] - 1] = bop_op(*(int *)(m + 7), c->reg[m[2] - 1], op);
		c->carry = !c->reg[m[3] - 1];
		return ;
	}
	if (c->types[1] == T_DIR_CODE)
	{
		if (m[6] > 16 || !m[6])
			return ;
		c->reg[m[6] - 1] = bop_op(*(int *)(m + 7), *(int *)(m + 2), op);
		c->carry = !c->reg[m[6] - 1];
		return ;
	}
	if (m[4] > 16 || !m[4])
		return ;
	rev_endian(m + 2, 2);
	memory_read(area, c->pos + *(short *)(m + 2) % IDX_MOD, m + 11, 4);
	c->reg[m[4] - 1] = bop_op(*(int *)(m + 7), *(int *)(m + 11), op);
	c->carry = !c->reg[m[4] - 1];
}

int		ldi_lldi(t_cursor *c, char *area, char *m, int f)
{
	int32_t	addr;

	if (c->types[1] == T_REG_CODE)
	{
		if (m[(int)m[20]] > 16 || m[(int)m[20]] < 1)
			return (-1);
		((int *)(m + 12))[0] = c->reg[(int)m[(int)m[20]] - 1];
		rev_endian(m + 12, 4);
		m[11] = m[m[20] + 1];
	}
	else if (c->types[1] == T_DIR_CODE)
	{
		memory_read(m + m[20], 0, m + 12, IND_SIZE);
		rev_endian(m + 12, 2);
		((int *)(m + 12))[0] = *(short *)(m + 12);
		m[11] = m[m[20] + 2];
	}
	else
		return (-1);
	if (m[11] > 16 || m[11] < 1)
		return (-1);
	addr = (*(int *)(m + 12) + *(int *)(m + 16)) % (f ? MEM_SIZE : IDX_MOD);
	memory_read(area, c->pos + addr, &c->reg[m[11] - 1], 4);
	return (c->reg[m[11] - 1] == 0);
}
