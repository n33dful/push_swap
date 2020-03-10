
#include "push_swap.h"

static int	*markup_func(int mode, t_selem *stack_elem)
{
	static int	last_elem;

	if (stack_elem)
	{
		if (mode == by_index_markup_mode && stack_elem->index == last_elem + 1)
		{
			stack_elem->keep = 1;
			last_elem = stack_elem->index;
		}
		else if (mode == by_number_markup_mode && stack_elem->number > last_elem)
		{
			stack_elem->keep = 1;
			last_elem = stack_elem->index;
		}
		else
			stack_elem->keep = 0;
	}
	return (&last_elem);
}

void		ft_stack_markup_elem(int mode, t_list *stack)
{
	if (mode == by_number_markup_mode)
		*markup_func(0, NULL) = ((t_selem *)stack->content)->number;
	else if (mode == by_index_markup_mode)
		*markup_func(0, NULL) = ((t_selem *)stack->content)->index;
	((t_selem *)stack->content)->keep = 1;
	stack = stack->next;
	while (stack)
	{
		markup_func(mode, stack->content);
		stack = stack->next;
	}
}
