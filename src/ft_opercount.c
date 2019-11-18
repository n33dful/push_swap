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

static t_stack	*ft_stackcpy(t_stack *stack)
{
	t_stack	*new;

	if (!stack)
		return (NULL);
	new = stacknew(stack);
	if (stack)
		new->next = ft_stackcpy(stack->next);
	return (new);
}

int				ft_opercount(t_stack **stacka, t_stack **stackb)
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
				ft_putstr("pa\n");
				len = ft_stacklen(a);
				count++;
				finish = 1;
			}
			else if (i == 0)
			{
				push(&b, &a);
				ft_putstr("pa\n");
				len = ft_stacklen(a);
				count++;
				finish = 1;
			}
			else
			{
				reverse_rotate(&a);
				ft_putstr("rra\n");
				count++;
				i--;
			}
		}
		else if (i + 1 == len)
		{
			rotate(&a);
			push(&b, &a);
			ft_putstr("ra\npa\n");
			len = ft_stacklen(a);
			finish = 1;
			count += 2;
			i++;
		}
		else
		{
			rotate(&a);
			ft_putstr("ra\n");
			count++;
			i++;
		}
		if (i == len)
			i = 0;
	}
	delete_stack(&a);
	delete_stack(&b);
	return (count);
}
