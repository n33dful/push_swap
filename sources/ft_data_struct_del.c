/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_struct_del.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:32:06 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/04 22:31:31 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_data_struct_del(t_data *data)
{
	if (data->sorted)
		ft_lstclear(&(data->sorted), NULL);
	if (data->stack_a)
		ft_lstclear(&(data->stack_a), free);
	if (data->stack_b)
		ft_lstclear(&(data->stack_b), free);
	if (data->by_index)
		ft_memdel((void *)(&data->by_index));
	if (data->by_number)
		ft_memdel((void *)(&data->by_number));
	if (data->tree)
		ft_treeclear(&data->tree, NULL);
	data->chosen = NULL;
	data->stack_a_len = 0;
	data->stack_b_len = 0;
}
