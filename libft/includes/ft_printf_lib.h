/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:26:05 by matruman          #+#    #+#             */
/*   Updated: 2019/11/06 13:29:54 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_LIB_H
# define FT_PRINTF_LIB_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

struct						s_flag
{
	char					hash;
	char					zero;
	char					space;
	char					plus;
	char					minus;
};

struct						s_mod
{
	char					h;
	char					hh;
	char					l;
	char					ll;
	char					bl;
};

typedef struct				s_float
{
	unsigned long long		m;
	int						e;
	char					sign;
	char					lflag;
	char					*str;
	char					*intpart;
	char					*fraction;
}							t_float;

typedef struct				s_format_list
{
	const char				*format;
	va_list					*ap;
	char					conv;
	struct s_flag			flag;
	struct s_mod			mod;
	int						position;
	int						len;
	int						width;
	int						precision;
	char					precision_flag;
	char					percent_flag;
	struct s_format_list	*next;
}							t_format_list;

typedef struct				s_buffer
{
	char					*buff;
	size_t					used;
	size_t					size;
}							t_buffer;

t_format_list				*get_format_list(const char *format, va_list *ap);
int							get_format(const char *format,
													t_format_list *format_list);
int							isconv(char c);
int							isflag(char c);
int							ismod(char c);
char						*ft_strndup(char *str, size_t n);
char						*ft_itoa_base(unsigned long long value, int base);
unsigned long long			get_unsigned(long long value);
t_float						*get_fl(t_format_list *format_list);
int							print_format_list(t_format_list *format_list,
													t_buffer *buffer);
int							print_conv_di(t_format_list *format_list,
											t_buffer *buffer);
int							print_conv_pouxx(t_format_list *format_list,
											t_buffer *buffer);
int							print_conv_cp(t_format_list *format_list,
											t_buffer *buffer);
int							print_conv_s(t_format_list *format_list,
											t_buffer *buffer);
int							print_conv_float(t_format_list *format_list,
											t_buffer *buffer);
char						*add_prefix(char *str, int count, char c);
char						*add_suffix(char *str, int count, char c);
void						ft_strcap(char *str);
void						free_format_list(t_format_list *list);
void						pf_buffer_init(t_buffer *buffer, int size);
void						buffer_chadd(t_buffer *buffer, char c);
int							pf_buffer_add(t_buffer	*buffer, const char *str,
											size_t size);
int							ft_printf(const char *format, ...);

#endif
