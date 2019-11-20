/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                     :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:41:19 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/20 16:28:06 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*ft_elemcpy(t_stack *stack);

t_stack			*ft_stackcpy(t_stack *stack)
{
	t_stack	*new;

	if (!stack)
		return (NULL);
	new = ft_elemcpy(stack);
	new->next = ft_stackcpy(stack->next);
	return (new);
}

static t_stack	*ft_elemcpy(t_stack *stack)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		exit(-1);
	new->num = stack->num;
	new->index = stack->index;
	new->markup = stack->markup;
	new->turns = stack->turns;
	new->keep = stack->keep;
	new->next = NULL;
	return (new);
}
