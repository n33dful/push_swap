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

#include "push_swap.h"

void	ft_stack_push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;

	if ((*stack_from))
	{
		tmp = (*stack_from);
		(*stack_from) = (*stack_from)->next;
		tmp->next = (*stack_to);
		(*stack_to) = tmp;
	}
}
