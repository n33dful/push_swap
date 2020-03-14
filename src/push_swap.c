/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:16:20 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/23 16:26:46 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_align_stack(t_data *data)
{
	size_t	index;
	char	*cmd;

	index = ((t_selem *)data->stack_a->content)->index;
	cmd = index <= data->stack_a_len / 2 ? "rra" : "ra";
	while (((t_selem *)data->stack_a->content)->index != 0)
		ft_stack_rotation(with_print, cmd, data);
}

int			main(int argc, char **argv)
{
	t_data	data;

	ft_data_struct_init(&data);
	if (argc > 1)
	{
		if (!ft_stack_new(argc, argv, &data))
			data.exit_code = -1;
		else if (!ft_stack_indexing(&data))
			data.exit_code = -1;
		else if (!ft_stack_markup(&data))
			data.exit_code = -1;
		else
		{
			ft_stack_divorce(&data);
			ft_stack_wedding(&data);
			ft_align_stack(&data);
		}
	}
	ft_data_struct_del(&data);
	if (data.exit_code == -1)
		ft_putendl("Error");
	return (data.exit_code);
}
