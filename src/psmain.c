/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:16:20 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/07 23:40:44 by cdarci           ###   ########.fr       */
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

void		bubble_sort_high(t_stack **stack)
{
	int	len;
	int	i;

	i = 0;
	len = stack_len((*stack));
	while (i < len)
	{
		if (i == 0 || (*stack)->num < (*stack)->next->num)
		{
			ra(stack);
			i++;
		}
		else
		{
			sa(stack);
			rra(stack);
			i--;
		}
	}
	ra(stack);
}

void		bubble_sort_low(t_stack **stack)
{
	int	current;
	int	len;
	int	i;

	i = 0;
	len = stack_len((*stack)) - 1;
	while (i < len)
	{
		ra(stack);
		current = (*stack)->num;
		rra(stack);
		if ((*stack)->num < current)
		{
			sa(stack);
			ra(stack);
		}
		ra(stack);
		i++;
	}
	ra(stack);
}

int			main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc < 2)
		exit(-1);
	a = create_stack(argc, argv);
	b = NULL;
	
	pb(&a, &b);
	ra(&a);
	pa(&a, &b);
	ra(&a);
	ra(&a);
	ra(&a);
	pb(&a, &b);
	sa(&a);
	rra(&a);
	pa(&a, &b);
	ra(&a);
	ft_putstr("pb\nra\npa\nra\nra\nra\npb\nsa\nrra\npa\nra\n");
	/*
	** 6 4 8 1 9 3 2
	*/
	delete_stack(&a);
	return (0);
}