/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:18:52 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/15 23:33:47 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_numlen(int num)
{
	int	len;

	len = 0;
	while (num / (num < 0 ? -10 : 10) > 0)
	{
		num /= 10;
		len++;
	}
	return (len + (num < 0 ? 2 : 1));
}

static void	ft_putstacknum(t_list *stack)
{
	t_selem	*stack_elem;
	int		i;

	i = 0;
	stack_elem = stack->content;
	if (stack)
	{
		while (i < ((13 - ft_numlen(stack_elem->number)) / 2))
		{
			ft_putchar(' ');
			i++;
		}
		ft_putnbr(stack_elem->number);
		i += ft_numlen(stack_elem->number);
		while (i < 13)
		{
			ft_putchar(' ');
			i++;
		}
	}
}

static void	ft_putstacks(t_list *stack_a, t_list *stack_b)
{
	while (stack_a || stack_b)
	{
		ft_putstr("|");
		if (stack_a)
		{
			ft_putstacknum(stack_a);
			stack_a = stack_a->next;
		}
		else
			ft_putstr("             ");
		ft_putstr("|");
		if (stack_b)
		{
			ft_putstacknum(stack_b);
			stack_b = stack_b->next;
		}
		else
			ft_putstr("             ");
		ft_putendl("|");
	}
}

void		ft_stack_print(char *cmd, t_list *stack_a, t_list *stack_b)
{
	if (cmd)
	{
		ft_putstr("\033[1;33m>----------{ ");
		ft_putstr(cmd);
		if (ft_strlen(cmd) == 2)
			ft_putendl("  }----------<\033[0m");
		else
			ft_putendl(" }----------<\033[0m");
	}
	ft_putendl("+-------------+-------------+");
	ft_putstacks(stack_a, stack_b);
	ft_putendl("+-------------+-------------+");
	ft_putendl("|      a      |      b      |");
	ft_putendl("+-------------+-------------+");
}
