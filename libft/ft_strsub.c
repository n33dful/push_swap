/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:23:01 by cdarci            #+#    #+#             */
/*   Updated: 2019/09/10 19:11:19 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;

	if (len + 1 == 0 || !s || !(str = ft_strnew(len)))
		return (NULL);
	ft_strncpy(str, &s[start], len);
	return (str);
}
