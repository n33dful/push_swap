/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_colored.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 20:08:28 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/02 20:16:40 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_colored(char const *s, char const *color)
{
	if (s && color)
	{
		ft_putstr_colored(s, color);
		ft_putchar('\n');
	}
}
