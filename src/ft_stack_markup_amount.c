
#include "push_swap.h"

int	ft_stack_markup_amount(t_list *stack)
{
	t_selem	*stack_elem;
	int		amount;

	amount = 0;
	while (stack)
	{
		stack_elem = stack->content;
		if (stack_elem->keep)
			amount++;
		stack = stack->next;
	}
	return (amount);
}
