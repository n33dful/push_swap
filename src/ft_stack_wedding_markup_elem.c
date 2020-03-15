/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_wedding_markup_elem.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:32:34 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/15 23:32:44 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_best_mode(int compare[4])
{
	if (compare[up_and_up_mode] <= compare[down_and_down_mode] && \
compare[up_and_up_mode] <= compare[up_and_down_mode] && \
compare[up_and_up_mode] <= compare[down_and_up_mode])
		return (up_and_up_mode);
	if (compare[down_and_down_mode] <= compare[up_and_up_mode] && \
compare[down_and_down_mode] <= compare[up_and_down_mode] && \
compare[down_and_down_mode] <= compare[down_and_up_mode])
		return (down_and_down_mode);
	if (compare[up_and_down_mode] <= compare[up_and_up_mode] && \
compare[up_and_down_mode] <= compare[down_and_down_mode] && \
compare[up_and_down_mode] <= compare[down_and_up_mode])
		return (up_and_down_mode);
	if (compare[down_and_up_mode] <= compare[up_and_up_mode] && \
compare[down_and_up_mode] <= compare[down_and_down_mode] && \
compare[down_and_up_mode] <= compare[up_and_up_mode])
		return (down_and_up_mode);
	return (-1);
}

static void	ft_set_down_and_down_turns(t_selem *stack_elem)
{
	int	rr_current;
	int	rr_next;

	rr_current = stack_elem->reverse_rotates_to_top;
	rr_next = stack_elem->elem_after->reverse_rotates_to_top;
	if (rr_current && rr_next)
		stack_elem->common_turns = rr_current < rr_next ? \
rr_current : rr_next;
	else
		stack_elem->common_turns = 0;
	if (stack_elem->common_turns < 0)
		stack_elem->common_turns = -1 * stack_elem->common_turns;
	else if (rr_current && rr_next && stack_elem->common_turns == 0)
		stack_elem->common_turns = stack_elem->total_turns;
}

static void	ft_set_up_and_up_turns(t_selem *stack_elem)
{
	int	r_current;
	int	r_next;

	r_current = stack_elem->rotates_to_top;
	r_next = stack_elem->elem_after->rotates_to_top;
	if (r_current && r_next)
		stack_elem->common_turns = r_current < r_next ? \
r_current : r_next;
	else
		stack_elem->common_turns = 0;
	if (stack_elem->common_turns < 0)
		stack_elem->common_turns = -1 * stack_elem->common_turns;
	else if (r_current && r_next && stack_elem->common_turns == 0)
		stack_elem->common_turns = stack_elem->total_turns;
}

void		ft_stack_wedding_markup_elem(int compare[4], t_selem *stack_elem)
{
	int		best_mode;

	best_mode = ft_find_best_mode(compare);
	stack_elem->total_turns = compare[best_mode];
	if (best_mode == up_and_up_mode)
		ft_set_up_and_up_turns(stack_elem);
	else if (best_mode == down_and_down_mode)
		ft_set_down_and_down_turns(stack_elem);
	else
		stack_elem->common_turns = 0;
	stack_elem->wedding_mode = best_mode;
}
