/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:44:11 by cdarci            #+#    #+#             */
/*   Updated: 2019/09/28 18:34:23 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while ((char)(s[i]) != c && (char)(s[i]))
		i++;
	if ((char)(s[i]) == c)
		return ((char *)(s + i));
	return (NULL);
}
