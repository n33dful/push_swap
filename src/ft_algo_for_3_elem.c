/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_for_3_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 13:29:47 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/23 14:04:46 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_algo_for_3_elem(t_stack **a)
{
	if ((*a)->index == 1 && (*a)->next->index == 0 && \
(*a)->next->next->index == 2)
		ft_putendl("sa");
	else if ((*a)->index == 2 && (*a)->next->index == 1 && \
(*a)->next->next->index == 0)
		ft_putendl("sa\nrra");
	else if ((*a)->index == 2 && (*a)->next->index == 0 && \
(*a)->next->next->index == 1)
		ft_putendl("ra");
	else if ((*a)->index == 0 && (*a)->next->index == 2 && \
(*a)->next->next->index == 1)
		ft_putendl("sa\nra");
	else if ((*a)->index == 1 && (*a)->next->index == 2 && \
(*a)->next->next->index == 0)
		ft_putendl("rra");
}
