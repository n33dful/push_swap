
#include "push_swap.h"

void	ft_data_struct_init(t_data *data)
{
	data->by_index = NULL;
	data->by_number = NULL;
	data->chosen = NULL;
	data->exit_code = 0;
	data->sorted = NULL;
	data->stack_a = NULL;
	data->stack_a_len = 0;
	data->stack_b = NULL;
	data->stack_b_len = 0;
}
