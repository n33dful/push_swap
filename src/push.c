/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:51:28 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/10 19:12:08 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack *tmp;

	if ((*stack1))
	{
		tmp = (*stack1);
		(*stack1) = (*stack1)->next;
		tmp->next = (*stack2);
		(*stack2) = tmp;
	}
}
