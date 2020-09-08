/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 02:22:25 by cdarci            #+#    #+#             */
/*   Updated: 2020/05/09 03:41:45 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t n)
{
	char			*str;
	unsigned int	i;

	if (!s || !(str = ft_strnew(n)))
		return (NULL);
	i = 0;
	while (i < n)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
