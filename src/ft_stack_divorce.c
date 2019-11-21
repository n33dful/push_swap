
#include "../include/push_swap.h"

static t_stack	*ft_find_max_markup(t_stack *stack);
static int		ft_is_swap_required(t_stack **stack);
static int		ft_check_for_false(t_stack *stack);
static void		ft_place_maximum_markup_on_top(t_stack **stack);

void			ft_stack_divorce(t_stack **a, t_stack **b)
{
	ft_markup_head(a);
	ft_place_maximum_markup_on_top(a);
	ft_markup(a);
	while (ft_check_for_false((*a)))
	{
		if (ft_is_swap_required(a))
		{
			ft_stack_swap(a);
			ft_markup(a);
			ft_putstr("sa\n");
		}
		else if ((*a)->markup == 0)
		{
			ft_stack_push(a, b);
			ft_putstr("pb\n");
		}
		else
		{
			ft_stack_rotate(a);
			ft_putstr("ra\n");
		}
	}
}

static int		ft_check_for_false(t_stack *stack)
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

static t_stack	*ft_find_max_markup(t_stack *stack)
{
	t_stack	*elem_with_max_markup;
	int		max_markup;

	max_markup = stack->markup;
	elem_with_max_markup = stack;
	while (stack)
	{
		if (stack->markup > max_markup)
		{
			max_markup = stack->markup;
			elem_with_max_markup = stack;
		}
		stack = stack->next;
	}
	return (elem_with_max_markup);
}

static int		ft_is_swap_required(t_stack **stack)
{
	t_stack	*a;
	t_stack	*cpy;
	int		keep;

	a = (*stack);
	keep = ft_markup_count(a);
	cpy = ft_stack_dup(a);
	ft_stack_swap(&cpy);
	ft_markup(&cpy);
	if (ft_markup_count(cpy) > keep)
	{
		ft_stack_del(&cpy);
		return (1);
	}
	ft_stack_del(&cpy);
	return (0);
}

static void	ft_place_maximum_markup_on_top(t_stack **stack)
{
	t_stack	*stack_elem_with_max_markup;
	int		max_markup;

	stack_elem_with_max_markup = ft_find_max_markup((*stack));
	max_markup = stack_elem_with_max_markup->markup;
	if (stack_elem_with_max_markup->index < ft_stack_len((*stack)) / 2)
	{
		while ((*stack)->keep != max_markup)
		{
			ft_stack_rotate(stack);
			ft_putstr("ra\n");
		}
	}
	else
	{
		while ((*stack)->keep != max_markup)
		{
			ft_stack_reverse_rotate(stack);
			ft_putstr("rra\n");
		}
	}
	stack_elem_with_max_markup = NULL;
}
