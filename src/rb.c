/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:27:59 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/10 19:12:08 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	rb(t_stack **b)
{
	t_stack	*tmp;
	size_t	adr;
	
	tmp = NULL;
	adr = (size_t)(*b);
	if ((*b))
	{
		while ((*b)->next)
			(*b) = (*b)->next;
		(*b)->next = (t_stack *)adr;
		(*b) = (*b)->next;
		tmp = (*b)->next;
		(*b)->next = NULL;
		(*b) = tmp;
	}
}
