/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_wedding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:32:17 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/04 22:35:19 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		*ft_set_rotates_amount(char mode, t_elem *elem)
{
	static int	turns[2];

	if (elem)
	{
		elem->rotates_to_top = turns[OBVERSE]++;
		elem->reverse_rotates_to_top = turns[REVERSE]--;
		elem->in_stack_a = (mode == A ? 1 : 0);
		elem->in_stack_b = (mode == B ? 1 : 0);
	}
	return (turns);
}

static void		ft_rotates_recalculating_in(char mode, t_data *data)
{
	t_list	*stack;
	int		length;

	length = (mode == A ? data->stack_a_len : data->stack_b_len);
	stack = (mode == A ? data->stack_a : data->stack_b);
	if (length)
	{
		ft_set_rotates_amount(0, NULL)[OBVERSE] = 0;
		if (length == 1)
			ft_set_rotates_amount(0, NULL)[REVERSE] = 0;
		else
			ft_set_rotates_amount(0, NULL)[REVERSE] = length;
		while (stack)
		{
			ft_set_rotates_amount(mode, stack->content);
			stack = stack->next;
		}
	}
}

static t_elem	*ft_elem_with_min_turns(t_list *stack)
{
	t_elem	*elem;
	t_elem	*min_elem;
	int		min_turns;

	elem = stack->content;
	min_turns = elem->total_turns;
	min_elem = elem;
	while (stack)
	{
		elem = stack->content;
		if (elem->total_turns < min_turns)
		{
			min_turns = elem->total_turns;
			min_elem = elem;
		}
		stack = stack->next;
	}
	return (min_elem);
}

void			ft_stack_wedding(t_data *data)
{
	ft_lstloop_create(data->sorted);
	ft_rotates_recalculating_in(A, data);
	ft_rotates_recalculating_in(B, data);
	while (data->stack_b)
	{
		ft_stack_wedding_markup(data);
		ft_stack_wedding_elem(ft_elem_with_min_turns(data->stack_b), data);
		ft_stack_rotate(LOUD, "pa", data);
		ft_rotates_recalculating_in(A, data);
		ft_rotates_recalculating_in(B, data);
	}
	ft_lstloop_break(data->sorted);
}
