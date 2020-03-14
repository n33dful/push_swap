
#include "push_swap.h"

static int		(*reindex_func(t_selem *stack_elem))[2]
{
	static int	turns[2];

	if (stack_elem)
	{
		stack_elem->rotates_to_top = turns[rotates_to_top]++;
		stack_elem->reverse_rotates_to_top = turns[reverse_rotates_to_top]--;
	}
	return (&turns);
}

static void		ft_reindexing(int mode, t_data *data)
{
	t_list	*stack;
	size_t	lenght;

	lenght = mode == reindex_stack_a ? data->stack_a_len : data->stack_b_len;
	stack = mode == reindex_stack_a ? data->stack_a : data->stack_b;
	if (lenght)
	{
		(*reindex_func(NULL))[rotates_to_top] = 0;
		if (lenght == 1)
			(*reindex_func(NULL))[reverse_rotates_to_top] = 0;
		else
			(*reindex_func(NULL))[reverse_rotates_to_top] = lenght;
		while (stack)
		{
			reindex_func(stack->content);
			stack = stack->next;
		}
	}
}

static void		ft_set_stack_a(t_list *elem)
{
	t_selem	*stack_elem;

	stack_elem = elem->content;
	stack_elem->in_stack_a = 1;
	stack_elem->in_stack_b = 0;
}

static void		ft_set_stack_b(t_list *elem)
{
	t_selem	*stack_elem;

	stack_elem = elem->content;
	stack_elem->in_stack_a = 0;
	stack_elem->in_stack_b = 1;
}

void			ft_stack_wedding_update(t_data *data)
{
	ft_reindexing(reindex_stack_a, data);
	ft_lstiter(data->stack_b, ft_set_stack_b);
	ft_lstiter(data->stack_a, ft_set_stack_a);
	ft_reindexing(reindex_stack_b, data);
}
