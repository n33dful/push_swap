
#include "push_swap.h"

static void		ft_up_up_wedding(t_selem *stack_elem, t_data *data)
{
	int current_turn;

	current_turn = 0;
	while (current_turn++ < stack_elem->common_turns)
		ft_stack_rotation(with_print, "rr", data);
	current_turn--;
	while (current_turn++ < stack_elem->elem_after->rotates_to_top)
		ft_stack_rotation(with_print, "ra", data);
	current_turn--;
	while (current_turn++ < stack_elem->rotates_to_top)
		ft_stack_rotation(with_print, "rb", data);
}

static void		ft_down_down_wedding(t_selem *stack_elem, t_data *data)
{
	int current_turn;

	current_turn = 0;
	while (current_turn++ < stack_elem->common_turns)
		ft_stack_rotation(with_print, "rrr", data);
	current_turn--;
	while (current_turn++ < stack_elem->elem_after->reverse_rotates_to_top)
		ft_stack_rotation(with_print, "rra", data);
	current_turn--;
	while (current_turn++ < stack_elem->reverse_rotates_to_top)
		ft_stack_rotation(with_print, "rrb", data);
}

static void		ft_up_down_wedding(t_selem *stack_elem, t_data *data)
{
	int current_turn;

	current_turn = 0;
	while (current_turn++ < stack_elem->reverse_rotates_to_top)
		ft_stack_rotation(with_print, "rrb", data);
	current_turn = 0;
	while (current_turn++ < stack_elem->elem_after->rotates_to_top)
		ft_stack_rotation(with_print, "ra", data);
}

static void		ft_down_up_wedding(t_selem *stack_elem, t_data *data)
{
	int current_turn;

	current_turn = 0;
	while (current_turn++ < stack_elem->rotates_to_top)
		ft_stack_rotation(with_print, "rb", data);
	current_turn = 0;
	while (current_turn++ < stack_elem->elem_after->reverse_rotates_to_top)
		ft_stack_rotation(with_print, "rra", data);
}

void			ft_stack_wedding_elem(t_selem *stack_elem, t_data *data)
{
	if (stack_elem->wedding_mode == up_and_up_mode)
		ft_up_up_wedding(stack_elem, data);
	else if (stack_elem->wedding_mode == down_and_down_mode)
		ft_down_down_wedding(stack_elem, data);
	else if (stack_elem->wedding_mode == up_and_down_mode)
		ft_up_down_wedding(stack_elem, data);
	else if (stack_elem->wedding_mode == down_and_up_mode)
		ft_down_up_wedding(stack_elem, data);
}
