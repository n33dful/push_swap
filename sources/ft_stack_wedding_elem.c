/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_wedding_elem.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:32:49 by cdarci            #+#    #+#             */
/*   Updated: 2020/08/30 19:52:48 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_up_up_wedding(t_elem *elem, t_data *data)
{
	int current_turn;

	current_turn = 0;
	while (current_turn++ < elem->common_turns)
		ft_stack_rotate(LOUD, "rr", data);
	current_turn--;
	while (current_turn++ < elem->elem_after->rotates_to_top)
		ft_stack_rotate(LOUD, "ra", data);
	current_turn--;
	while (current_turn++ < elem->rotates_to_top)
		ft_stack_rotate(LOUD, "rb", data);
}

static void	ft_down_down_wedding(t_elem *elem, t_data *data)
{
	int current_turn;

	current_turn = 0;
	while (current_turn++ < elem->common_turns)
		ft_stack_rotate(LOUD, "rrr", data);
	current_turn--;
	while (current_turn++ < elem->elem_after->reverse_rotates_to_top)
		ft_stack_rotate(LOUD, "rra", data);
	current_turn--;
	while (current_turn++ < elem->reverse_rotates_to_top)
		ft_stack_rotate(LOUD, "rrb", data);
}

static void	ft_up_down_wedding(t_elem *elem, t_data *data)
{
	int current_turn;

	current_turn = 0;
	while (current_turn++ < elem->reverse_rotates_to_top)
		ft_stack_rotate(LOUD, "rrb", data);
	current_turn = 0;
	while (current_turn++ < elem->elem_after->rotates_to_top)
		ft_stack_rotate(LOUD, "ra", data);
}

static void	ft_down_up_wedding(t_elem *elem, t_data *data)
{
	int current_turn;

	current_turn = 0;
	while (current_turn++ < elem->rotates_to_top)
		ft_stack_rotate(LOUD, "rb", data);
	current_turn = 0;
	while (current_turn++ < elem->elem_after->reverse_rotates_to_top)
		ft_stack_rotate(LOUD, "rra", data);
}

void		ft_stack_wedding_elem(t_elem *elem, t_data *data)
{
	if (elem->wedding_mode == UP_AND_UP)
		ft_up_up_wedding(elem, data);
	else if (elem->wedding_mode == DOWN_AND_DOWN)
		ft_down_down_wedding(elem, data);
	else if (elem->wedding_mode == UP_AND_DOWN)
		ft_up_down_wedding(elem, data);
	else
		ft_down_up_wedding(elem, data);
}
