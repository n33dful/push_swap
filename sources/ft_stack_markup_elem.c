
#include "push_swap.h"

static int	*markup_func(int mode, t_selem *stack_elem)
{
	static int	last_elem;

	if (stack_elem)
	{
		if (mode == markup_by_index && \
		stack_elem->index == last_elem + 1)
		{
			stack_elem->keep = 1;
			last_elem = stack_elem->index;
		}
		else if (mode == markup_by_number && \
		stack_elem->number > last_elem)
		{
			stack_elem->keep = 1;
			last_elem = stack_elem->number;
		}
		else
			stack_elem->keep = 0;
	}
	return (&last_elem);
}

void		ft_stack_markup_elem(int mode, t_list *stack)
{
	if (mode == markup_by_number)
		*markup_func(0, NULL) = ((t_selem *)stack->content)->number;
	else if (mode == markup_by_index)
		*markup_func(0, NULL) = ((t_selem *)stack->content)->index;
	((t_selem *)stack->content)->keep = 1;
	stack = stack->next;
	while (stack)
	{
		markup_func(mode, stack->content);
		stack = stack->next;
	}
}
