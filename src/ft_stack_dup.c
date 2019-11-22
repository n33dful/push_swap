/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:16:58 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/21 20:17:05 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*ft_elemcpy(t_stack *stack)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		exit(-1);
	new->num = stack->num;
	new->index = stack->index;
	new->markup = stack->markup;
	new->turns = stack->turns;
	if (stack->str)
		new->str = ft_strdup(stack->str);
	else
		new->str = NULL;
	new->next = NULL;
	return (new);
}

t_stack			*ft_stack_dup(t_stack *stack)
{
	t_stack	*new;

	if (!stack)
		return (NULL);
	new = ft_elemcpy(stack);
	new->next = ft_stack_dup(stack->next);
	return (new);
}
