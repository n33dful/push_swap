/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:16:20 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/08 19:30:39 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void		bubble_sorta(t_stack **a)
{
	int	curra;
	int	lena;
	int	i;

	i = 0;
	lena = stack_len((*a));
	while (i < lena)
	{
		ra(a);
		curra = (*a)->num;
		rra(a);
		ft_putstr("ra\nrra\n");
		if (i == 0 || (*a)->num < curra)
		{
			ra(a);
			ft_putstr("ra\n");
			i++;
		}
		else
		{
			sa(a);
			rra(a);
			ft_putstr("sa\nrra\n");
			i--;
		}
	}
	ra(a);
	ft_putstr("ra\n");
}

void		bubble_sortb(t_stack **b)
{
	int	curra;
	int	lenb;
	int	i;

	i = 0;
	lenb = stack_len((*b));
	while (i < lenb)
	{
		rb(b);
		curra = (*b)->num;
		rrb(b);
		ft_putstr("rb\nrrb\n");
		if (i == 0 || (*b)->num < curra)
		{
			rb(b);
			ft_putstr("rb\n");
			i++;
		}
		else
		{
			sb(b);
			rrb(b);
			ft_putstr("sb\nrrb\n");
			i--;
		}
	}
	rb(b);
	ft_putstr("rb\n");
}

void	insert(t_stack **a, t_stack **b)
{
	int	len;
	int	i;

	i = 0;
	len = stack_len((*a));
	while ((*b))
	{
		if (i == len - 1 && (*b)->num > (*a)->num)
		{
			pa(a, b);
			ft_putstr("pa\n");
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
		if (i == len)
			i = 0;
	}
	while (i > 0)
	{
		rra(a);
		ft_putstr("rra\n");
		i--;
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
	bubble_sorta(&a);
	bubble_sortb(&b);
	insert(&a, &b);
	delete_stack(&a);
	return (0);
}