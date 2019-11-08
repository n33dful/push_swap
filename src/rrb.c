/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:47:33 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/05 20:48:25 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	size_t	adr;

	adr = (size_t)(*b);
	if ((*b))
	{
		while ((*b)->next)
			(*b) = (*b)->next;
		(*b)->next = (t_stack *)adr;
		adr = (size_t)(*b);
		while ((*b)->next != (t_stack *)(adr))
			(*b) = (*b)->next;
		tmp = (*b)->next;
		(*b)->next = NULL;
		(*b) = tmp;
	}
}
