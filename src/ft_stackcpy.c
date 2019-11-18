#include "../include/push_swap.h"

static t_stack	*stacknew(t_stack *stack)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		exit(-1);
	new->num = stack->num;
	new->index = stack->index;
	new->markup = stack->markup;
	new->next = NULL;
	return (new);
}

t_stack			*ft_stackcpy(t_stack *stack)
{
	t_stack	*new;

	if (!stack)
		return (NULL);
	new = stacknew(stack);
	new->next = ft_stackcpy(stack->next);
	return (new);
}
