
#ifndef PUSH_SWAP_STRUCTS_H
# define PUSH_SWAP_STRUCTS_H

# include "push_swap.h"

typedef	enum			e_markup_mode
{
	markup_by_index,
	markup_by_number
}						t_markup_mode;

typedef enum			e_print_mode
{
	with_print,
	without_print
}						t_print_mode;

typedef enum			e_push_mode
{
	push_to_stack_a,
	push_to_stack_b
}						t_push_mode;

typedef enum			e_rotate_mode
{
	rotate_stack_a,
	rotate_stack_b
}						t_rotate_mode;

typedef enum			e_swap_mode
{
	swap_stack_a,
	swap_stack_b
}						t_swap_mode;

typedef enum			e_reindexing_mode
{
	reindex_stack_a,
	reindex_stack_b
}						t_reindexing_mode;

typedef enum			e_turns_to_top_markup
{
	rotates_to_top,
	reverse_rotates_to_top
}						t_turns_to_top_makrup;

typedef enum			e_wedding_mode
{
	up_and_up_mode,
	down_and_down_mode,
	up_and_down_mode,
	down_and_up_mode
}						t_wedding_mode;

typedef struct			s_stack_elem
{
	int					number;
	int					index;
	int					keep;
	int					rotates_to_top;
	int					reverse_rotates_to_top;
	int					wedding_mode;
	int					common_turns;
	int					total_turns;
	int					in_stack_a;
	int					in_stack_b;
	struct s_stack_elem	*elem_after;
}						t_selem;

typedef struct			s_markup
{
	t_list				*markup_head;
	int					saved;
	int					mode;
}						t_markup;

typedef struct			s_wedding_struct
{
	int					turns_compare[4];
	int					best_mode;
	t_list				*stack;
	t_selem				*stack_elem;
}						t_wedding;

typedef struct			s_data
{
	int					exit_code;
	t_markup			*chosen;
	t_markup			*by_index;
	t_markup			*by_number;
	t_list				*stack_a;
	t_list				*stack_b;
	size_t				stack_a_len;
	size_t				stack_b_len;
	t_list				*sorted;
}						t_data;

#endif