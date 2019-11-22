/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:26:21 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/22 22:58:43 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isint(const char *str)
{
	long long	num;
	int			is_negative;

	num = 0;
	is_negative = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			is_negative = 1;
	}
	if (*str == '\0')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		if ((is_negative ? num < num * 10 : num > num * 10))
			return (0);
		else if (is_negative)
			num = num * 10 - (*str - '0');
		else
			num = num * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0' || num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}
