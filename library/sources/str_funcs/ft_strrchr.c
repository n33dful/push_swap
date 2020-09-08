/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:48:55 by cdarci            #+#    #+#             */
/*   Updated: 2020/05/09 02:07:50 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (1)
	{
		if ((char)s[i] == (char)c)
			return ((char *)(s + i));
		if (!i)
			break ;
		i--;
	}
	return (NULL);
}
