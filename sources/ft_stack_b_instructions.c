/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_b_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:57:10 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/21 19:57:13 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ft_stack_b_instructions(int count)
{
	char	*comm;
	int		i;

	i = 0;
	comm = ft_strnew(0);
	while (i < (count < 0 ? -1 * count : count))
	{
		comm = (count < 0 ? ft_combine_instructions(comm, "rrb") : \
ft_combine_instructions(comm, "rb"));
		i++;
	}
	return (comm);
}
