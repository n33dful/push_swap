/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_a_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:56:42 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/23 16:32:05 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static size_t	ft_max_i(t_selem *stack)
{
	size_t	ind;

	ind = stack->index;
	while (stack)
	{
		if (stack->index > ind)
			ind = stack->index;
		stack = stack->next;
	}
	return (ind);
}

static size_t	ft_min_i(t_selem *stack)
{
	size_t	ind;

	ind = stack->index;
	while (stack)
	{
		if (stack->index < ind)
			ind = stack->index;
		stack = stack->next;
	}
	return (ind);
}

static char		*ft_rr_rotate(t_selem **a, t_selem **b)
{
	char	*commands;
	size_t	index_start;
	size_t	tmp;

	index_start = (*a)->index;
	commands = ft_strnew(0);
	while (1)
	{
		tmp = (*a)->index;
		ft_stack_reverse_rotate(a);
		if ((*a)->index == ft_min_i((*a)) && (*b)->index < (*a)->index)
		{
			commands = ft_combine_instructions(commands, "rra");
			break ;
		}
		else if ((*a)->index == ft_max_i((*a)) && (*b)->index > (*a)->index)
			break ;
		else if ((*a)->index < (*b)->index && (*b)->index < tmp)
			break ;
		commands = ft_combine_instructions(commands, "rra");
	}
	while ((*a)->index != index_start)
		ft_stack_rotate(a);
	return (commands);
}

static char		*ft_r_rotate(t_selem **a, t_selem **b)
{
	char	*commands;
	size_t	index_start;
	size_t	tmp;

	index_start = (*a)->index;
	commands = ft_strnew(0);
	tmp = (*a)->index;
	while (1)
	{
		if ((*a)->index == ft_min_i((*a)) && (*b)->index < (*a)->index)
			break ;
		else if ((*a)->index == ft_max_i((*a)) && (*b)->index > (*a)->index)
		{
			commands = ft_combine_instructions(commands, "ra");
			break ;
		}
		else if ((*a)->index > (*b)->index && (*b)->index > tmp)
			break ;
		tmp = (*a)->index;
		ft_stack_rotate(a);
		commands = ft_combine_instructions(commands, "ra");
	}
	while ((*a)->index != index_start)
		ft_stack_reverse_rotate(a);
	return (commands);
}

char			*ft_stack_a_instructions(t_selem **stacka, t_selem **stackb)
{
	char	*comm_r;
	char	*comm_rr;

	comm_r = ft_r_rotate(stacka, stackb);
	comm_rr = ft_rr_rotate(stacka, stackb);
	if (ft_number_of_operations(comm_r) > ft_number_of_operations(comm_rr))
	{
		ft_strdel(&comm_r);
		return (comm_rr);
	}
	ft_strdel(&comm_rr);
	return (comm_r);
}
