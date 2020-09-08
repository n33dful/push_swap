/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:18:52 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/02 20:30:11 by cdarci           ###   ########.fr       */
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
	t_elem	*elem;
	int		i;

	i = 0;
	elem = stack->content;
	if (stack)
	{
		while (i < ((13 - ft_numlen(elem->number)) / 2))
		{
			ft_putchar(' ');
			i++;
		}
		ft_putnbr(elem->number);
		i += ft_numlen(elem->number);
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
			ft_putstacknum(stack_a);
		else
			ft_putstr("             ");
		ft_putstr("|");
		if (stack_b)
			ft_putstacknum(stack_b);
		else
			ft_putstr("             ");
		ft_putendl("|");
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
	}
}

static void	ft_print_command(char const *command)
{
	if (command)
	{
		ft_putstr_colored(">----------{ ", YELLOW);
		ft_putstr_colored(command, YELLOW);
		if (ft_strlen(command) == 2)
			ft_putendl_colored("  }----------<", YELLOW);
		else
			ft_putendl_colored(" }----------<", YELLOW);
	}
}

void		ft_stack_print(char const *cmd, t_list *stack_a, t_list *stack_b)
{
	ft_print_command(cmd);
	ft_putendl("+-------------+-------------+");
	ft_putstacks(stack_a, stack_b);
	ft_putendl("+-------------+-------------+");
	ft_putendl("|      a      |      b      |");
	ft_putendl("+-------------+-------------+");
}
