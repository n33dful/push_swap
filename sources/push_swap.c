/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:16:20 by cdarci            #+#    #+#             */
/*   Updated: 2020/11/15 22:01:30 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_stack_align(t_data *data)
{
	char	*cmd;
	int		index;

	index = ((t_elem *)data->stack_a->content)->index;
	cmd = (index <= data->stack_a_len / 2 ? "rra" : "ra");
	while (((t_elem *)data->stack_a->content)->index != 0)
		ft_stack_rotate(LOUD, cmd, data);
}

static void	ft_stack_sort(t_data *data)
{
	ft_stack_divorce(data);
	ft_stack_wedding(data);
	ft_stack_align(data);
}

int			main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (argc > 1)
	{
		if (!ft_stack_new(argc, argv, &data))
			data.exit_code = 1;
		else if (!ft_stack_markup(&data))
			data.exit_code = 1;
		else
			ft_stack_sort(&data);
	}
	ft_data_cleaning(&data);
	if (data.exit_code == 1)
		ft_putendl_fd("Error", 2);
	return (data.exit_code);
}
