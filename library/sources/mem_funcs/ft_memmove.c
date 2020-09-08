/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:57:31 by cdarci            #+#    #+#             */
/*   Updated: 2020/05/09 00:28:32 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t n)
{
	unsigned char	*dst2;
	unsigned char	*src2;
	size_t			i;

	i = 0;
	if (src == dst)
		return (dst);
	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	if (src > dst)
	{
		while (i < n)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
			dst2[i] = src2[i];
	}
	return (dst);
}
