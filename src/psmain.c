/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:16:20 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/10 20:24:38 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int			stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

void		bubble_sort(t_stack **a, t_stack **b)
{
	int	lena;
	int	lenb;
	int	i;
	int	j;

	i = 0;
	j = 0;
	lena = stack_len((*a));
	lenb = stack_len((*b));
	while (i < lena || j < lenb)
	{
		if ((i == 0 && j == 0) || ((*a)->next && (*a)->num < (*a)->next->num && (*b)->next && (*b)->num < (*b)->next->num))
		{
			rr(a, b);
			ft_putstr("rr\n");
			i++;
			j++;
		}
		else if (i == 0 || ((*a)->next && (*a)->num < (*a)->next->num))
		{
			ra(a);
			ft_putstr("ra\n");
			i++;
		}
		else if (j == 0 || ((*b)->next && (*b)->num < (*b)->next->num))
		{
			rb(b);
			ft_putstr("rb\n");
			j++;
		}
		else if (i >= lena)
		{
			sb(b);
			rrb(b);
			ft_putstr("sb\nrrb\n");
			j--;
		}
		else if (j >= lenb)
		{
			sa(a);
			rra(a);
			ft_putstr("sa\nrra\n");
			i--;
		}
		else
		{
			ss(a, b);
			rrr(a, b);
			ft_putstr("ss\nrrr\n");
			i--;
			j--;
		}
	}
	rr(a, b);
	ft_putstr("rr\n");
}

void	insert(t_stack **a, t_stack **b)
{
	int	len;
	int	i;

	i = 0;
	len = stack_len((*a));
	while ((*b))
	{
		if (i == len && (*b)->num > (*a)->num)
		{
			ra(a);
			pa(a, b);
			ft_putstr("ra\npa\n");
			len = stack_len((*a));
		}
		else if ((*b)->num < (*a)->num)
		{
			pa(a, b);
			ft_putstr("pa\n");
			len = stack_len((*a));
		}
		else
		{
			ra(a);
			ft_putstr("ra\n");
			i++;
		}
	}
	while (i < len)
	{
		ra(a);
		ft_putstr("ra\n");
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int		len;
	int		i;

	i = 0;
	if (argc < 2)
		exit(-1);
	a = create_stack(argc, argv);
	b = NULL;
	len = stack_len(a);
	while (i < len / 2)
	{
		pb(&a, &b);
		ft_putstr("pb\n");
		i++;
	}
	bubble_sort(&a, &b);
	insert(&a, &b);
	delete_stack(&a);
	return (0);
}