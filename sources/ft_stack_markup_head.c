/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_markup_head.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:33:02 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/15 23:33:04 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_markup_head(t_data *data)
{
	t_list	*first_elem;

	first_elem = data->stack_a;
	while (data->stack_a != data->chosen->markup_head)
		ft_stack_rotate(SILENT, "ra", data);
	ft_stack_markup_elem(data->chosen->mode, data->stack_a);
	while (data->stack_a != first_elem)
		ft_stack_rotate(SILENT, "ra", data);
	data->chosen->saved = ft_stack_markup_amount(data->stack_a);
}
