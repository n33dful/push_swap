/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:15:01 by cdarci            #+#    #+#             */
/*   Updated: 2019/09/08 18:41:55 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while ((unsigned char)haystack[i] != '\0')
	{
		if ((unsigned char)haystack[i] == (unsigned char)needle[0])
		{
			if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
