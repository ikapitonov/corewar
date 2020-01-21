#ifndef COREWAR_DISASSEMBLY_H
#define COREWAR_DISASSEMBLY_H

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

typedef union 	s_bits
{
	char		str[4];
	int			num;
	t_keybits	arr[4];
}				t_bits;

#endif
