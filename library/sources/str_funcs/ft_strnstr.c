/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:28:13 by cdarci            #+#    #+#             */
/*   Updated: 2020/05/09 00:21:05 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t n)
{
	size_t	hslen;
	size_t	ndlen;
	size_t	i;

	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	ndlen = ft_strlen(needle);
	hslen = ft_strlen(haystack);
	while ((char)haystack[i] && ndlen + i <= hslen && ndlen + i <= n && i < n)
	{
		if ((char)haystack[i] == (char)needle[0])
		{
			if (!ft_strncmp(haystack + i, needle, ndlen))
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
