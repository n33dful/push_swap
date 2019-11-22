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

int	ft_stack_len(t_stack *stack)
{
	t_stack	*tmp;
	int		len;

	len = 0;
	tmp = stack;
	while (tmp)
	{
		if (len > len + 1)
			return (-1);
		tmp = tmp->next;
		len++;
	}
	tmp = NULL;
	return (len);
}
