/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combine_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:53:14 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/21 21:26:42 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ft_combine_instructions(char *first_comm, char *second_comm)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(second_comm, "\n");
	res = ft_strjoin(first_comm, tmp);
	ft_strdel(&tmp);
	ft_strdel(&first_comm);
	return (res);
}
