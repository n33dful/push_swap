/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_wedding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:32:17 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/15 23:32:19 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_selem	*ft_elem_with_min_turns(t_list *stack)
{
	t_selem	*stack_elem;
	t_selem	*min_elem;
	int		min_turns;

	stack_elem = stack->content;
	min_turns = stack_elem->total_turns;
	min_elem = stack_elem;
	while (stack)
	{
		stack_elem = stack->content;
		if (stack_elem->total_turns < min_turns)
		{
			min_turns = stack_elem->total_turns;
			min_elem = stack_elem;
		}
		stack = stack->next;
	}
	return (min_elem);
}

static void		ft_nullify_trash(t_list *stack)
{
	t_selem	*stack_elem;

	stack_elem = stack->content;
	stack_elem->keep = 1;
	stack_elem->total_turns = 0;
	stack_elem->elem_after = NULL;
	stack_elem->common_turns = 0;
	stack_elem->wedding_mode = -1;
}

void			ft_stack_wedding(t_data *data)
{
	ft_lstloop_create(data->sorted);
	ft_stack_wedding_update(data);
	while (data->stack_b)
	{
		ft_stack_wedding_markup(data);
		ft_stack_wedding_elem(ft_elem_with_min_turns(data->stack_b), data);
		ft_stack_rotation(with_print, "pa", data);
		ft_stack_wedding_update(data);
	}
	ft_lstiter(data->stack_a, ft_nullify_trash);
	ft_lstloop_break(data->sorted);
}
