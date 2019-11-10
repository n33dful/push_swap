/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:09:31 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/10 19:12:08 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	pb(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if ((*a))
	{
		tmp = (*a);
		(*a) = (*a)->next;
		tmp->next = (*b);
		(*b) = tmp;
	}
}
