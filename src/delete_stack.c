#include "../incl/push_swap.h"

void	delete_stack(t_stack **stack)
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
