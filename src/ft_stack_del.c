/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:57:15 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/23 16:16:03 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_stack_del(t_stack **stack)
{
	t_stack	*tmp;

	while ((*stack))
	{
		tmp = (*stack)->next;
		ft_strdel(&((*stack)->str));
		free((*stack));
		(*stack) = NULL;
		(*stack) = tmp;
	}
	stack = NULL;
	tmp = NULL;
}
