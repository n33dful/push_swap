
#include "push_swap.h"

void	ft_init_data(t_data *data)
{
	data->exit_code = 0;
	data->markup = NULL;
	data->sorted = NULL;
	data->stack_a = NULL;
	data->stack_a_len = 0;
	data->stack_b = NULL;
	data->stack_b_len = 0;
}	

void	ft_del_data(t_data *data)
{
	if (data->stack_a)
		ft_lstdel(&(data->stack_a), del_stack_elem);
	if (data->stack_b)
		ft_lstdel(&(data->stack_b), del_stack_elem);
	if (data->sorted)
		ft_lstdel(&(data->sorted), del_stack_elem);
	if (data->markup)
		ft_memdel((void *)(&data->markup));
}
