/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:18:52 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/21 20:19:04 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static int	ft_numlen(int num)
{
	int	len;

	len = 0;
	while (num / 10 > 0)
	{
		num /= 10;
		len++;
	}
	return ((num < 0 ? len + 2 : len + 1));
}

static void	ft_putstacknum(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack)
	{
		while (i < ((13 - ft_numlen(stack->num)) / 2))
		{
			ft_putchar(' ');
			i++;
		}
		ft_putnbr(stack->num);
		i += ft_numlen(stack->num);
		while (i < 13)
		{
			ft_putchar(' ');
			i++;
		}
	}
}

static void	ft_putstacks(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		ft_putstr("|");
		if (a)
		{
			ft_putstacknum(a);
			a = a->next;
		}
		else
			ft_putstr("             ");
		ft_putstr("|");
		if (b)
		{
			ft_putstacknum(b);
			b = b->next;
		}
		else
			ft_putstr("             ");
		ft_putendl("|");
	}
}

void		ft_stack_print(t_stack *a, t_stack *b)
{
	ft_putendl("+-------------+-------------+");
	ft_putstacks(a, b);
	ft_putendl("+-------------+-------------+");
	ft_putendl("|      a      |      b      |");
	ft_putendl("+-------------+-------------+");
}
