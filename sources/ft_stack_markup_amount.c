/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_markup_amount.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:33:11 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/15 23:33:13 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_markup_amount(t_list *stack)
{
	t_elem	*elem;
	int		amount;

	amount = 0;
	while (stack)
	{
		elem = stack->content;
		if (elem->keep)
			amount++;
		stack = stack->next;
	}
	return (amount);
}
