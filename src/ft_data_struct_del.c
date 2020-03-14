
#include "push_swap.h"

void	ft_data_struct_del(t_data *data)
{
	if (data->stack_a)
		ft_lstdel(&(data->stack_a), ft_stack_elem_del);
	if (data->stack_b)
		ft_lstdel(&(data->stack_b), ft_stack_elem_del);
	if (data->sorted)
		ft_lstdel(&(data->sorted), ft_stack_elem_del);
	if (data->by_number)
		ft_memdel((void *)(&data->by_index));
	if (data->by_number)
		ft_memdel((void *)(&data->by_number));
	data->chosen = NULL;
}
