/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:05:59 by cdarci            #+#    #+#             */
/*   Updated: 2020/05/09 01:27:03 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t n)
{
	size_t res;
	size_t i;
	size_t j;

	j = 0;
	i = ft_strlen(dst);
	res = ft_strlen(src);
	if (n <= i)
		res += n;
	else
		res += i;
	while (src[j] && i + 1 < n)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (res);
}
