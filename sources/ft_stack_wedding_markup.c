/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_wedding_markup.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:32:28 by cdarci            #+#    #+#             */
/*   Updated: 2020/08/30 19:50:44 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_calculate_turns(t_elem *elem, int (*compare)[4])
{
	int	r_current;
	int	rr_current;
	int	r_next;
	int	rr_next;

	r_current = elem->rotates_to_top;
	rr_current = elem->reverse_rotates_to_top;
	r_next = elem->elem_after->rotates_to_top;
	rr_next = elem->elem_after->reverse_rotates_to_top;
	if (r_current > r_next)
		(*compare)[UP_AND_UP] = r_current;
	else
		(*compare)[UP_AND_UP] = r_next;
	if (rr_current > rr_next)
		(*compare)[DOWN_AND_DOWN] = rr_current;
	else
		(*compare)[DOWN_AND_DOWN] = rr_next;
	(*compare)[UP_AND_DOWN] = rr_current + r_next;
	(*compare)[DOWN_AND_UP] = r_current + rr_next;
}

void		ft_stack_wedding_markup(t_data *data)
{
	int		turns_compare[4];
	t_elem	*elem;
	t_list	*stack;

	stack = data->stack_b;
	while (stack)
	{
		while (stack->content != data->sorted->content)
			data->sorted = data->sorted->next;
		elem = stack->content;
		while (!((t_elem *)data->sorted->content)->in_stack_a)
			data->sorted = data->sorted->next;
		elem->elem_after = data->sorted->content;
		ft_calculate_turns(elem, &turns_compare);
		ft_stack_wedding_markup_elem(turns_compare, elem);
		stack = stack->next;
	}
}
