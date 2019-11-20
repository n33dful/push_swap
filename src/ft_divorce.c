
#include "../include/push_swap.h"

static void	ft_markup(t_stack **stack);
static int	ft_checkfalse(t_stack *stack);
static int	ft_keepcount(t_stack *stack);
static int	ft_swapneed(t_stack **stack);

void		ft_divorce(t_stack **a, t_stack **b)
{
	ft_markuphead(a);
	ft_putmaxkeepontop(a);
	ft_markup(a);
	while (ft_checkfalse((*a)))
	{
		if (ft_swapneed(a))
		{
			swap(a);
			ft_markup(a);
			ft_putstr("sa\n");
		}
		else if ((*a)->markup == 0)
		{
			push(a, b);
			ft_putstr("pb\n");
		}
		else
		{
			rotate(a);
			ft_putstr("ra\n");
		}
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

static int	ft_checkfalse(t_stack *stack)
{
	t_stack *a;

	a = stack;
	while (a)
	{
		if (a->markup == 0)
			return (1);
		a = a->next;
	}
	return (0);
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

static int	ft_swapneed(t_stack **stack)
{
	t_stack	*a;
	t_stack	*cpy;
	int		keep;

	a = (*stack);
	keep = ft_keepcount(a);
	cpy = ft_stackcpy(a);
	swap(&cpy);
	ft_markup(&cpy);
	if (ft_keepcount(cpy) > keep)
	{
		ft_stackdel(&cpy);
		return (1);
	}
	ft_stackdel(&cpy);
	return (0);
}
