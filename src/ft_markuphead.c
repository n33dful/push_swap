
#include "../include/push_swap.h"

static void	ft_markup(t_stack **stack);
static int	ft_keepcount(t_stack *stack);

void		ft_markuphead(t_stack **stack)
{
	int		len;
	int		i;

	i = 0;
	len = ft_stacklen((*stack));
	while (i < len)
	{
		ft_markup(stack);
		(*stack)->keep = ft_keepcount((*stack));
		rotate(stack);
		i++;
	}
}

static void	ft_markup(t_stack **stack)
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

static int	ft_keepcount(t_stack *stack)
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
