
#include "push_swap.h"

void	ft_stack_markup_head(t_data *data)
{
	t_list	*first_elem;

	first_elem = data->stack_a;
	while (data->stack_a != data->markup->markup_head)
		ft_stack_rotation(without_print, "ra", data);
	ft_stack_markup_elem(data->markup->mode, data->stack_a);
	while (data->stack_a != first_elem)
		ft_stack_rotation(without_print, "ra", data);
	data->markup->saved = ft_stack_markup_amount(data->stack_a);
}
