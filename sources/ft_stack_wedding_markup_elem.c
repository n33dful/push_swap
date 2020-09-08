/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_wedding_markup_elem.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:32:34 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/04 23:06:46 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	ft_find_best_mode(int compare_modes[4])
{
	char	best_mode;
	int		min_turns;

	min_turns = compare_modes[UP_AND_UP];
	best_mode = UP_AND_UP;
	if (compare_modes[DOWN_AND_DOWN] < min_turns)
	{
		min_turns = compare_modes[DOWN_AND_DOWN];
		best_mode = DOWN_AND_DOWN;
	}
	if (compare_modes[UP_AND_DOWN] < min_turns)
	{
		min_turns = compare_modes[UP_AND_DOWN];
		best_mode = UP_AND_DOWN;
	}
	if (compare_modes[DOWN_AND_UP] < min_turns)
	{
		min_turns = compare_modes[DOWN_AND_UP];
		best_mode = DOWN_AND_UP;
	}
	return (best_mode);
}

static void	ft_set_down_and_down_turns(t_elem *elem)
{
	int	rr_current;
	int	rr_next;

	rr_current = elem->reverse_rotates_to_top;
	rr_next = elem->elem_after->reverse_rotates_to_top;
	if (rr_current && rr_next)
		elem->common_turns = rr_current < rr_next ? \
rr_current : rr_next;
	else
		elem->common_turns = 0;
	if (elem->common_turns < 0)
		elem->common_turns = -1 * elem->common_turns;
	else if (rr_current && rr_next && elem->common_turns == 0)
		elem->common_turns = elem->total_turns;
}

static void	ft_set_up_and_up_turns(t_elem *elem)
{
	int	r_current;
	int	r_next;

	r_current = elem->rotates_to_top;
	r_next = elem->elem_after->rotates_to_top;
	if (r_current && r_next)
		elem->common_turns = r_current < r_next ? r_current : r_next;
	else
		elem->common_turns = 0;
	if (elem->common_turns < 0)
		elem->common_turns = -1 * elem->common_turns;
	else if (r_current && r_next && elem->common_turns == 0)
		elem->common_turns = elem->total_turns;
}

void		ft_stack_wedding_markup_elem(int compare_modes[4], t_elem *elem)
{
	int	best_mode;

	best_mode = ft_find_best_mode(compare_modes);
	elem->total_turns = compare_modes[best_mode];
	if (best_mode == UP_AND_UP)
		ft_set_up_and_up_turns(elem);
	else if (best_mode == DOWN_AND_DOWN)
		ft_set_down_and_down_turns(elem);
	else
		elem->common_turns = 0;
	elem->wedding_mode = best_mode;
}
