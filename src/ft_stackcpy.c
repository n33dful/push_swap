#include "../include/push_swap.h"

static t_stack	*ft_elemcpy(t_stack *stack);

t_stack			*ft_stackcpy(t_stack *stack)
{
	t_stack	*new;

	if (!stack)
		return (NULL);
	new = ft_elemcpy(stack);
	new->next = ft_stackcpy(stack->next);
	return (new);
}

static t_stack	*ft_elemcpy(t_stack *stack)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		exit(-1);
	new->num = stack->num;
	new->index = stack->index;
	new->markup = stack->markup;
	new->turns = stack->turns;
	new->next = NULL;
	return (new);
}
