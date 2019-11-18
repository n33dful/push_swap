#include "../include/push_swap.h"

static int	ft_opercount(t_stack **stacka, t_stack **stackb);

void		ft_turnsindex(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmp;
	t_stack *a;
	t_stack	*b;
	int		i;
	int		len;

	i = 0;
	a = ft_stackcpy(*stacka);
	b = ft_stackcpy(*stackb);
	len = ft_stacklen(b);
	while (i < len / 2)
	{
		b->turns = ft_opercount(&a, &b) + i;
		rotate(&b);
		i++;
	}
	while (i > 0)
	{
		reverse_rotate(&b);
		i--;
	}
	i = 0;
	while (i < len / 2)
	{
		reverse_rotate(&b);
		b->turns = -1 * (ft_opercount(&a, &b) + i % len + 1);
		i++;
	}
	while (i > 0)
	{
		rotate(&b);
		i--;
	}
	tmp = (*stackb);
	while (b)
	{
		tmp->turns = b->turns;
		b = b->next;
		tmp = tmp->next;
	}
	tmp = NULL;
	delete_stack(&a);
	delete_stack(&b);
}

static int	ft_opercount(t_stack **stacka, t_stack **stackb)
{
	int		count;
	int		finish;
	int		tmp;
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		len;

	count = 0;
	finish = 0;
	a = ft_stackcpy((*stacka));
	b = ft_stackcpy((*stackb));
	i = 0;
	len = ft_stacklen(a);
	while (!finish)
	{
		if (b->index < a->index)
		{
			reverse_rotate(&a);
			tmp = a->index;
			rotate(&a);
			if (b->index > tmp)
			{
				push(&b, &a);
				len = ft_stacklen(a);
                count++;
				finish = 1;
			}
			else if (i == 0)
			{
				push(&b, &a);
				len = ft_stacklen(a);
                count++;
				finish = 1;
			}
			else
			{
				reverse_rotate(&a);
                count++;
				i--;
			}
		}
		else if (i + 1 == len)
		{
			rotate(&a);
			push(&b, &a);
			len = ft_stacklen(a);
            count += 2;
			finish = 1;
			i++;
		}
		else
		{
			reverse_rotate(&a);
			tmp = a->index;
			rotate(&a);
			if (b->index > a->index)
			{
				rotate(&a);
                count++;
				i++;
			}
			else if (i - 1 != 0 && b->index > tmp)
			{
				push(&b, &a);
				len = ft_stacklen(a);
				finish = 1;
                count++;
				i = len - 1;
			}
		}
		if (i == len)
			i = 0;
	}
	delete_stack(&a);
	delete_stack(&b);
	return (count);
}
