/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:32:23 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/05 20:47:09 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;
	size_t	adr;

	adr = (size_t)(*a);
	if ((*a))
	{
		while ((*a)->next)
			(*a) = (*a)->next;
		(*a)->next = (t_stack *)adr;
		adr = (size_t)(*a);
		while ((*a)->next != (t_stack *)(adr))
			(*a) = (*a)->next;
		tmp = (*a)->next;
		(*a)->next = NULL;
		(*a) = tmp;
	}
}
