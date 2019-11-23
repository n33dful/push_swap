/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:53:20 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/23 15:57:18 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_delete_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		ft_strdel(&(arr[i++]));
	free(arr);
	arr = NULL;
}
