#include "../include/push_swap.h"

void	ft_stackdel(t_stack **stack)
{
	t_stack	*tmp;

	while ((*stack))
	{
		tmp = (*stack)->next;
		free((*stack));
		(*stack) = NULL;
		(*stack) = tmp;
	}
	tmp = NULL;
}
