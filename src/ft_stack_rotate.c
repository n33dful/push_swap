/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:14:26 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/21 21:27:32 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_stack_rotate(t_stack **stack)
{
	t_stack	*tmp;
	size_t	adr;

	tmp = NULL;
	adr = (size_t)(*stack);
	if ((*stack))
	{
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		(*stack)->next = (t_stack *)adr;
		(*stack) = (*stack)->next;
		tmp = (*stack)->next;
		(*stack)->next = NULL;
		(*stack) = tmp;
	}
}
