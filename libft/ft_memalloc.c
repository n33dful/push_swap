/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:36:15 by cdarci            #+#    #+#             */
/*   Updated: 2019/09/09 17:27:44 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = (void *)malloc(size)))
		exit(-1);
	ft_bzero(mem, size);
	return (mem);
}
