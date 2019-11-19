#include "../include/push_swap.h"

static int	ft_opercount(t_stack **stacka, t_stack **stackb);
static void	from_head(t_stack **stacka, t_stack **stackb);
static void	from_tail(t_stack **stacka, t_stack **stackb);

void		ft_turnsindex(t_stack **stacka, t_stack **stackb)
{
	from_head(stacka, stackb);
	from_tail(stacka, stackb);
}

static void		from_head(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmp;
	t_stack *a;
	t_stack	*b;
	int		len;
	int		i;

	i = 0;
	a = ft_stackcpy((*stacka));
	b = ft_stackcpy((*stackb));
	tmp = (*stackb);
	len = ft_stacklen(b);
	while (i < len / 2)
	{
		tmp->turns = ft_opercount(&a, &b) + i;
		tmp = tmp->next;
		i++;
	}
	delete_stack(&a);
	delete_stack(&b);
}

static void		from_tail(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmp;
	t_stack *a;
	t_stack	*b;
	int		len;
	int		i;

	a = ft_stackcpy(*stacka);
	b = ft_stackcpy(*stackb);
	tmp = (*stackb);
	len = ft_stacklen(b);
	i = 0;
	while (i < len / 2)
	{
		tmp = tmp->next;
		reverse_rotate(&b);
		i++;
	}
	while (i > 0)
	{
		tmp->turns = -1 * (ft_opercount(&a, &b) + i);
		tmp = tmp->next;
		i--;
	}
	delete_stack(&a);
	delete_stack(&b);
}

static int	maxind(t_stack *stack)
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

static int	minind(t_stack *stack)
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

static int	ft_opercount(t_stack **stacka, t_stack **stackb)
{
	int		count;
	int		finish;
	int		tmp;

	count = 0;
	finish = 0;
	while (!finish && (*stackb))
	{
		tmp = (*stacka)->index;
		if ((*stacka)->index == minind((*stacka)) && ((*stackb))->index < (*stacka)->index)
		{
			push(stackb, stacka);
			count++;
			finish = 1;
		}
		else if ((*stacka)->index == maxind((*stacka)) && ((*stackb))->index > (*stacka)->index)
		{
			rotate(stacka);
			push(stackb, stacka);
			count += 2;
			finish = 1;
		}
		else if ((*stackb)->index - (*stacka)->index > 0)
		{
			rotate(stacka);
			count++;
			if ((*stacka)->index > ((*stackb))->index && ((*stackb))->index > tmp)
			{
				push(stackb, stacka);
				count ++;
				finish = 1;
			}
		}
		else
		{
			reverse_rotate(stacka);
			if ((*stacka)->index < ((*stackb))->index && ((*stackb))->index < tmp)
			{
				rotate(stacka);
				push(stackb, stacka);
				count++;
				finish = 1;
			}
			else
				count++;
		}
	}
	return (count);
}
