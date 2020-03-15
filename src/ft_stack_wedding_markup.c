/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_wedding_markup.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:32:28 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/15 23:32:31 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_calculate_turns(t_selem *stack_elem, int (*compare)[4])
{
	int	r_current;
	int	rr_current;
	int	r_next;
	int	rr_next;

	r_current = stack_elem->rotates_to_top;
	rr_current = stack_elem->reverse_rotates_to_top;
	r_next = stack_elem->elem_after->rotates_to_top;
	rr_next = stack_elem->elem_after->reverse_rotates_to_top;
	if (r_current > r_next)
		(*compare)[up_and_up_mode] = r_current;
	else
		(*compare)[up_and_up_mode] = r_next;
	if (rr_current > rr_next)
		(*compare)[down_and_down_mode] = rr_current;
	else
		(*compare)[down_and_down_mode] = rr_next;
	(*compare)[up_and_down_mode] = rr_current + r_next;
	(*compare)[down_and_up_mode] = r_current + rr_next;
}

void			ft_stack_wedding_markup(t_data *data)
{
	int		turns_compare[4];
	t_selem	*stack_elem;
	t_list	*stack;

	stack = data->stack_b;
	while (stack)
	{
		while (stack->content != data->sorted->content)
			data->sorted = data->sorted->next;
		stack_elem = stack->content;
		while (!((t_selem *)data->sorted->content)->in_stack_a)
			data->sorted = data->sorted->next;
		stack_elem->elem_after = data->sorted->content;
		ft_calculate_turns(stack_elem, &turns_compare);
		ft_stack_wedding_markup_elem(turns_compare, stack_elem);
		stack = stack->next;
	}
}
