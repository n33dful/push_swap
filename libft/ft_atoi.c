/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:49:03 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/05 19:14:06 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int			ft_atoi(const char *str)
{
	unsigned long long	num;
	int					is_negative;

	num = 0;
	is_negative = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = 1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		if (num > num * 10)
			return (is_negative ? 0 : -1);
		str++;
	}
	return (is_negative ? (-1 * (int)num) : (int)num);
}
