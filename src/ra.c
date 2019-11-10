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

#include "../incl/push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;
	size_t	adr;
	
	tmp = NULL;
	adr = (size_t)(*a);
	if ((*a))
	{
		while ((*a)->next)
			(*a) = (*a)->next;
		(*a)->next = (t_stack *)adr;
		(*a) = (*a)->next;
		tmp = (*a)->next;
		(*a)->next = NULL;
		(*a) = tmp;
	}
}
