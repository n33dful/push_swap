/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:05:17 by cdarci            #+#    #+#             */
/*   Updated: 2019/09/10 19:07:54 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putendl(char const *s)
{
	unsigned int	len;

	len = 0;
	if (s)
	{
		while (s[len])
			len++;
		write(1, s, len);
		ft_putchar('\n');
	}
}
