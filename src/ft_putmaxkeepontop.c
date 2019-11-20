#include "../include/push_swap.h"

static int	ft_findmaxkeep(t_stack *stack);

void		ft_putmaxkeepontop(t_stack **stack)
{
	int	maxkeep;

	maxkeep = ft_findmaxkeep((*stack));
	while ((*stack)->keep != maxkeep)
	{
		rotate(stack);
		ft_putstr("ra\n");
	}
}

static int	ft_findmaxkeep(t_stack *stack)
{
	int	keep;

	keep = stack->keep;
	while (stack)
	{
		if (stack->keep > keep)
			keep = stack->keep;
		stack = stack->next;
	}
	return (keep);
}
