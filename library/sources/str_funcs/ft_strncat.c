/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:02:10 by cdarci            #+#    #+#             */
/*   Updated: 2020/05/09 01:27:21 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char const *s2, size_t n)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	if (n > ft_strlen(s2))
	{
		while ((char)s2[i])
		{
			s1[i + len] = (char)s2[i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			s1[i + len] = (char)s2[i];
			i++;
		}
	}
	s1[i + len] = '\0';
	return (s1);
}
