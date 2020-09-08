/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 18:54:57 by student           #+#    #+#             */
/*   Updated: 2020/08/28 19:31:15 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrdel(void ***array)
{
	size_t	i;

	i = 0;
	if ((*array))
	{
		while ((*array)[i])
			ft_memdel(&((*array)[i++]));
		ft_memdel((void*)array);
	}
}
