/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:14:26 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/10 19:12:08 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack **stack)
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
