/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:16:20 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/23 16:26:46 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_final_stack_rotation(t_stack **a)
{
	if ((*a)->index > ft_stack_len((*a)) / 2)
	{
		while ((*a)->index != 0)
		{
			ft_stack_rotate(a);
			ft_putendl("ra");
		}
	}
	else
	{
		while ((*a)->index != 0)
		{
			ft_stack_reverse_rotate(a);
			ft_putendl("rra");
		}
	}
}

static char	*ft_findcomm(t_stack *stack)
{
	char	*res;
	int		min;

	res = NULL;
	if (stack)
	{
		min = stack->turns;
		res = stack->str;
		while (stack)
		{
			if (stack->turns != 0 && \
((stack->turns < 0 ? -1 * stack->turns : stack->turns) < min))
			{
				min = stack->turns;
				res = stack->str;
			}
			stack = stack->next;
		}
	}
	return (res);
}

static void	ft_base_algorithm(t_stack **a, t_stack **b)
{
	ft_stack_divorce(a, b);
	while ((*b))
	{
		ft_countturns(a, b);
		ft_putstr(ft_findcomm((*b)));
		ft_instruction_execution(ft_findcomm((*b)), a, b);
	}
	ft_final_stack_rotation(a);
}

int			main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	if (ac < 2 || !(a = ft_stack_new(ac, av)))
	{
		if (ac < 2)
			return (0);
		ft_putendl("Error");
		exit(-1);
	}
	b = NULL;
	ft_stack_indexind(&a);
	if (ft_stack_len(a) == 3)
		ft_algo_for_3_elem(&a);
	else
		ft_base_algorithm(&a, &b);
	ft_stack_del(&a);
	ft_stack_del(&b);
	return (0);
}
