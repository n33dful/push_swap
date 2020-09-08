/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:45:27 by cdarci            #+#    #+#             */
/*   Updated: 2020/05/09 14:19:48 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start_point(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static size_t	ft_end_point(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i > 0 && ft_strchr(set, s1[i]))
		i--;
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_end_point(s1, set);
	start = ft_start_point(s1, set);
	if (!(result = ft_strnew(start <= end ? end - start + 1 : 0)))
		return (NULL);
	while (start <= end)
		result[i++] = (char)s1[start++];
	result[i] = '\0';
	return (result);
}
