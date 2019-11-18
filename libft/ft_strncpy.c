/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:16:15 by cdarci            #+#    #+#             */
/*   Updated: 2019/09/28 18:32:29 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	if (len > ft_strlen(src))
	{
		while ((unsigned char)src[i] != '\0')
		{
			dst[i] = (unsigned char)src[i];
			i++;
		}
		while (i < len)
		{
			dst[i] = '\0';
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			dst[i] = (unsigned char)src[i];
			i++;
		}
	}
	return (dst);
}
