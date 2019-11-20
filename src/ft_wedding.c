#include "../include/push_swap.h"

void		ft_finalrotate(t_stack **a);
int			ft_findminindex(t_stack *stack);
int			ft_findmaxind(t_stack *stack);

void		ft_wedding(t_stack **a, t_stack **b)
{
	int		tmp;

	while (*b)
	{
		tmp = (*a)->index;
		if ((*a)->index == ft_findminindex((*a)) && (*b)->index < (*a)->index)
		{
			push(b, a);
			ft_putstr("pa\n");
		}
		else if ((*a)->index == ft_findmaxind((*a)) && (*b)->index > (*a)->index)
		{
			rotate(a);
			push(b, a);
			ft_putstr("ra\npa\n");
		}
		else if (((*b)->index > (ft_stacklen((*a)) / 4)) && ((*a)->index < (ft_stacklen((*a)) / 4)))
		{
			reverse_rotate(a);
			if ((*a)->index < (*b)->index && (*b)->index < tmp)
			{
				rotate(a);
				push(b, a);
				ft_putstr("pa\n");
			}
			else
				ft_putstr("rra\n");
		}
		else if (((*b)->index < (ft_stacklen((*a)) / 4)) && ((*a)->index > (ft_stacklen((*a)) / 4)))
		{
			rotate(a);
			ft_putstr("ra\n");
			if ((*a)->index > (*b)->index && (*b)->index > tmp)
			{
				push(b, a);
				ft_putstr("pa\n");
			}
		}
		else if ((*b)->index - (*a)->index > 0)
		{
			rotate(a);
			ft_putstr("ra\n");
			if ((*a)->index > (*b)->index && (*b)->index > tmp)
			{
				push(b, a);
				ft_putstr("pa\n");
			}
		}
		else
		{
			reverse_rotate(a);
			if ((*a)->index < (*b)->index && (*b)->index < tmp)
			{
				rotate(a);
				push(b, a);
				ft_putstr("pa\n");
			}
			else
				ft_putstr("rra\n");
		}
	}
	ft_finalrotate(a);
}

int			ft_findmaxind(t_stack *stack)
{
	int	ind;

	ind = stack->index;
	while (stack)
	{
		if (stack->index > ind)
			ind = stack->index;
		stack = stack->next;
	}
	return (ind);
}

int			ft_findminindex(t_stack *stack)
{
	int	ind;

	ind = stack->index;
	while (stack)
	{
		if (stack->index < ind)
			ind = stack->index;
		stack = stack->next;
	}
	return (ind);
}

void		ft_finalrotate(t_stack **a)
{
	if ((*a)->index > ft_stacklen((*a)) / 2)
	{
		while ((*a)->index != 0)
		{
			rotate(a);
			ft_putstr("ra\n");
		}
	}
	else
	{
		while ((*a)->index != 0)
		{
			reverse_rotate(a);
			ft_putstr("rra\n");
		}
	}
}
