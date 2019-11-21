/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allrotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:52:58 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/21 22:55:06 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_commcount(char *comm)
{
	int	count;

	count = 0;
	while (*comm)
	{
		if (*comm == '\n')
			count++;
		comm++;
	}
	return (count);
}

static void	ft_kostyil(t_stack **stackb, int len, int i)
{
	if (len % 2 && len != 1)
	{
		if ((*stackb)->str)
			ft_strdel(&((*stackb)->str));
		(*stackb)->turns = 0;
	}
	while (i > 0)
	{
		ft_stack_reverse_rotate(stackb);
		i--;
	}
}

static void	ft_rotate_instructions(t_stack **stacka, t_stack **stackb, int len)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 0;
	while (i < (len == 1 ? len : len / 2))
	{
		a = ft_stack_dup((*stacka));
		b = ft_stack_dup((*stackb));
		if ((*stackb)->str)
			ft_strdel(&((*stackb)->str));
		(*stackb)->str = \
ft_inctruction_optimization(ft_stack_a_instructions(&a, &b), \
ft_stack_b_instructions(i));
		(*stackb)->turns = ft_commcount((*stackb)->str);
		ft_stack_rotate(stackb);
		ft_stack_del(&a);
		ft_stack_del(&b);
		i++;
	}
	ft_kostyil(stackb, len, i);
}

static void	ft_reverse_rotate_instructions(t_stack **stacka, \
t_stack **stackb, int len)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = -1;
	while (i >= -1 * (len / 2))
	{
		ft_stack_reverse_rotate(stackb);
		a = ft_stack_dup((*stacka));
		b = ft_stack_dup((*stackb));
		if ((*stackb)->str)
			ft_strdel(&((*stackb)->str));
		(*stackb)->str = \
ft_inctruction_optimization(ft_stack_a_instructions(&a, &b), \
ft_stack_b_instructions(i));
		(*stackb)->turns = -1 * ft_commcount((*stackb)->str);
		ft_stack_del(&a);
		ft_stack_del(&b);
		i--;
	}
	while (i < -1)
	{
		ft_stack_rotate(stackb);
		i++;
	}
}

void		ft_countturns(t_stack **stacka, t_stack **stackb)
{
	ft_rotate_instructions(stacka, stackb, ft_stack_len((*stackb)));
	ft_reverse_rotate_instructions(stacka, stackb, ft_stack_len((*stackb)));
}
