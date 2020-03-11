
#include "push_swap.h"

static void		ft_update(t_markup *markup, t_list *stack)
{
	t_selem	*stack_elem;
	t_selem	*markup_head;
	int		saved;

	saved = ft_stack_markup_amount(stack);
	if (saved >= markup->saved)
	{
		stack_elem = stack->content;
		if (markup->markup_head && saved == markup->saved)
		{
			markup_head = markup->markup_head->content;
			if (markup_head->index > stack_elem->index)
				markup->markup_head = stack;
		}
		else
		{
			markup->markup_head = stack;
			markup->saved = saved;
		}
	}
}

static t_markup	*ft_markup_init(void)
{
	t_markup	*markup;

	if (!(markup = (t_markup *)malloc(sizeof(t_markup))))
		return (NULL);
	markup->markup_head = NULL;
	markup->saved = 0;
	markup->mode = 0;
	return (markup);
}

static t_markup	*ft_find_markup_head(int mode, t_data *data)
{
	t_markup	*markup;
	size_t		stack_len;
	size_t		i;

	if (!(markup = ft_markup_init()))
		return (NULL);
	i = 0;
	stack_len = ft_lstlen(data->stack_a);
	markup->mode = mode;
	while (i++ < stack_len)
	{
		ft_stack_markup_elem(markup->mode, data->stack_a);
		ft_update(markup, data->stack_a);
		ft_stack_rotation(without_print, "ra", data);
	}
	return (markup);
}

static int		ft_markup_del(t_markup **markup_to_del)
{
	if (markup_to_del && (*markup_to_del))
		ft_memdel((void *)markup_to_del);
	return (0);
}

int				ft_stack_markup(t_data *data)
{
	t_markup	*choosen;
	t_markup	*by_number;
	t_markup	*by_index;
    int         first_index;
    int         second_index;

	if (!(by_index = ft_find_markup_head(markup_by_index, data)))
		return (0);
	if (!(by_number = ft_find_markup_head(markup_by_number, data)))
		return (ft_markup_del(&by_index));
    first_index = ((t_selem *)by_index->markup_head->content)->index;
    second_index = ((t_selem *)by_number->markup_head->content)->index;
	if (by_index->saved < by_number->saved)
		choosen = by_number;
	else if (by_index->saved > by_number->saved)
		choosen = by_index;
	else if (first_index <= second_index)
		choosen = by_index;
	else
		choosen = by_number;
	data->markup = choosen;
	ft_markup_del(choosen == by_index ? &by_number : &by_index);
	ft_stack_markup_head(data);
	return (1);
}
