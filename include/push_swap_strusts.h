
#ifndef PUSH_SWAP_STRUCTS_H
# define PUSH_SWAP_STRUCTS_H

# include "push_swap.h"

typedef	enum		e_markup_mode
{
	by_index_markup_mode,
	by_number_markup_mode
}					t_mmode;

typedef enum		e_print_mode
{
	print_mode,
	not_print_mode
}					t_pmode;

typedef struct		s_stack_elem
{
	int				index;
	int				number;
	int				keep;
}					t_selem;

typedef struct		s_markup
{
	t_list			*markup_head;
	int				saved;
	int				mode;
}					t_markup;

#endif