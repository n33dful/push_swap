/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:45:27 by cdarci            #+#    #+#             */
/*   Updated: 2019/09/10 18:58:41 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_isspace(s[start]) && s[start])
		start++;
	end = ft_strlen(s) - 1;
	while (ft_isspace(s[end]) && end)
		end--;
	result = ft_strsub(s, start, (end > start ? end - start + 1 : 1));
	return (result);
}
