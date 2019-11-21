
#include "../include/push_swap.h"

int			ft_markup_count(t_stack *stack);
void		ft_markup(t_stack **stack);

void		ft_markup_head(t_stack **stack)
{
	int		len;
	int		i;

	i = 0;
	len = ft_stack_len((*stack));
	while (i < len)
	{
		ft_markup(stack);
		(*stack)->keep = ft_markup_count((*stack));
		ft_stack_rotate(stack);
		i++;
	}
}

int			ft_markup_count(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->markup == 1)
			count++;
		stack = stack->next;
	}
	return (count);
}

void		ft_markup(t_stack **stack)
{
	int		index;
	t_stack	*a;

	a = (*stack);
	index = a->index;
	a->markup = 1;
	a = a->next;
	while (a)
	{
		if (a->index == index + 1)
		{
			index = a->index;
			a->markup = 1;
		}
		else
			a->markup = 0;
		a = a->next;
	}
}
