/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allrotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:31:18 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/22 14:32:54 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_number_of_operations(const char *operations)
{
	int	count;

	count = 0;
	while (*operations)
	{
		if (*operations == '\n')
			count++;
		operations++;
	}
	return (count);
}
