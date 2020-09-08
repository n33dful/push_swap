/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_markup_elem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:33:06 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/03 19:36:29 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_markup(char mode, t_elem *elem)
{
	static int	last_elem;

	if (elem)
	{
		if (mode == BY_INDEX && elem->index == last_elem + 1)
		{
			elem->keep = 1;
			last_elem = elem->index;
		}
		else if (mode == BY_NUMBER && elem->number > last_elem)
		{
			elem->keep = 1;
			last_elem = elem->number;
		}
		else
			elem->keep = 0;
	}
	return (&last_elem);
}

void		ft_stack_markup_elem(char mode, t_list *stack)
{
	if (mode == BY_NUMBER)
		*ft_markup(0, NULL) = ((t_elem *)stack->content)->number;
	else if (mode == BY_INDEX)
		*ft_markup(0, NULL) = ((t_elem *)stack->content)->index;
	((t_elem *)stack->content)->keep = 1;
	stack = stack->next;
	while (stack)
	{
		ft_markup(mode, stack->content);
		stack = stack->next;
	}
}
