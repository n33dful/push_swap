/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_colored.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 20:09:08 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/02 20:16:35 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_colored(char const *s, char const *color)
{
	if (s && color)
	{
		ft_putstr(color);
		ft_putstr(s);
		ft_putstr("\033[0m");
	}
}
