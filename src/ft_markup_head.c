/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_markup_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:55:07 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/21 19:55:34 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		ft_markup_head(t_stack **stack)
{
	int		len;
	int		i;

	i = 0;
	len = ft_stack_len((*stack));
	while (i < len)
	{
		ft_markup(stack);
		(*stack)->keep = ft_markup_count((*stack));
		ft_stack_rotate(stack);
		i++;
	}
}

int			ft_markup_count(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->markup == 1)
			count++;
		stack = stack->next;
	}
	return (count);
}

void		ft_markup(t_stack **stack)
{
	int		index;
	t_stack	*a;

	a = (*stack);
	index = a->index;
	a->markup = 1;
	a = a->next;
	while (a)
	{
		if (a->index == index + 1)
		{
			index = a->index;
			a->markup = 1;
		}
		else
			a->markup = 0;
		a = a->next;
	}
}
