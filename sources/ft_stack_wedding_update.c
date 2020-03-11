
#include "push_swap.h"

static int		(*reindex_func(t_selem *stack_elem))[2]
{
	static int	index[2];

	if (stack_elem)
	{
		stack_elem->rotates_to_top = index[0]++;
		stack_elem->reverse_rotates_to_top = index[1]--;
	}
	return (&index);
}

static void		ft_reindexing(t_list *stack)
{
	size_t	stack_len;

	stack_len = ft_lstlen(stack);
	if (stack_len)
	{
		(*reindex_func(NULL))[0] = 0;
		if (stack_len == 1)
			(*reindex_func(NULL))[1] = 0;
		else
			(*reindex_func(NULL))[1] = stack_len;
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
	ft_reindexing(data->stack_a);
	ft_lstiter(data->stack_a, ft_set_stack_a);
	ft_reindexing(data->stack_b);
	ft_lstiter(data->stack_b, ft_set_stack_b);
}
