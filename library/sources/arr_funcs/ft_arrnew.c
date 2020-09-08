/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 19:19:55 by cdarci            #+#    #+#             */
/*   Updated: 2020/08/28 19:27:57 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_arrnew(size_t count)
{
	void	**arr;
	size_t	i;

	i = 0;
	if (!(arr = (void**)ft_calloc(count + 1, sizeof(void*))))
		return (NULL);
	while (i < count)
		arr[i++] = NULL;
	return (arr);
}
