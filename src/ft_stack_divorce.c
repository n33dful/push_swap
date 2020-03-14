/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_divorce.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:14:17 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/21 20:16:35 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swap_required(t_data *data)
{
	int		saved;

	saved = data->chosen->saved;
	ft_stack_rotation(without_print, "sa", data);
	ft_stack_markup_head(data);
	if (saved < data->chosen->saved)
		return (1);
	ft_stack_rotation(without_print, "sa", data);
	ft_stack_markup_head(data);
	return (0);
}

static int	ft_check_not_deivorsed(t_list *stack)
{
	while (stack)
	{
		if (!((t_selem *)stack->content)->keep)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void		ft_stack_divorce(t_data *data)
{
	while (ft_check_not_deivorsed(data->stack_a))
	{
		if (ft_swap_required(data))
			ft_putendl("sa");
		else if (!((t_selem *)data->stack_a->content)->keep)
			ft_stack_rotation(with_print, "pb", data);
		else
			ft_stack_rotation(with_print, "ra", data);
	}
}
