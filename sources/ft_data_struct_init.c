/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_struct_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:31:56 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/04 22:29:04 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	data->tree = NULL;
}
