
#include "push_swap.h"

static void		ft_update(t_markup *chosen, t_list *stack)
{
	t_selem	*stack_elem;
	t_selem	*markup_head;
	int		saved;

	saved = ft_stack_markup_amount(stack);
	if (saved >= chosen->saved)
	{
		stack_elem = stack->content;
		if (chosen->markup_head && saved == chosen->saved)
		{
			markup_head = chosen->markup_head->content;
			if (markup_head->index > stack_elem->index)
				chosen->markup_head = stack;
		}
		else
		{
			chosen->markup_head = stack;
			chosen->saved = saved;
		}
	}
}

static t_markup	*ft_markup_init(void)
{
	t_markup	*chosen;

	if (!(chosen = (t_markup *)malloc(sizeof(t_markup))))
		return (NULL);
	chosen->markup_head = NULL;
	chosen->saved = 0;
	chosen->mode = 0;
	return (chosen);
}

static t_markup	*ft_find_markup_head(int mode, t_data *data)
{
	t_markup	*chosen;
	size_t		stack_len;
	size_t		i;

	if (!(chosen = ft_markup_init()))
		return (NULL);
	i = 0;
	chosen->mode = mode;
	stack_len = data->stack_a_len;
	while (i++ < stack_len)
	{
		ft_stack_markup_elem(chosen->mode, data->stack_a);
		ft_update(chosen, data->stack_a);
		ft_stack_rotation(without_print, "ra", data);
	}
	return (chosen);
}

int				ft_stack_markup(t_data *data)
{
	int	elem_index[2];

	if (!(data->by_index = ft_find_markup_head(markup_by_index, data)))
		return (0);
	if (!(data->by_number = ft_find_markup_head(markup_by_number, data)))
		return (0);
	elem_index[markup_by_index] = \
((t_selem *)data->by_index->markup_head->content)->index;
	elem_index[markup_by_number] = \
((t_selem *)data->by_number->markup_head->content)->index;
	if (data->by_index->saved < data->by_number->saved)
		data->chosen = data->by_number;
	else if (data->by_index->saved > data->by_number->saved)
		data->chosen = data->by_index;
	else if (elem_index[markup_by_index] <= elem_index[markup_by_number])
		data->chosen = data->by_index;
	else
		data->chosen = data->by_number;
	ft_stack_markup_head(data);
	return (1);
}
