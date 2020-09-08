/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:16:15 by cdarci            #+#    #+#             */
/*   Updated: 2020/05/09 01:27:49 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char const *src, size_t n)
{
	size_t i;

	i = 0;
	if (n > ft_strlen(src))
	{
		while ((unsigned char)src[i] != '\0')
		{
			dst[i] = (unsigned char)src[i];
			i++;
		}
		while (i < n)
		{
			dst[i] = '\0';
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			dst[i] = (unsigned char)src[i];
			i++;
		}
	}
	return (dst);
}
