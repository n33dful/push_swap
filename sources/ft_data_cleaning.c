/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_cleaning.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:32:06 by cdarci            #+#    #+#             */
/*   Updated: 2020/11/15 23:45:52 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_data_cleaning(t_data *data)
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
	ft_bzero(data, sizeof(t_data));
}
