/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:17:47 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/21 20:17:51 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_stack_len(const t_stack *stack)
{
	size_t	len;

	len = 0;
	while (stack)
	{
		if (len > len + 1)
			return (-1);
		stack = stack->next;
		len++;
	}
	return (len);
}
