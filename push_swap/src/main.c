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

static void	print_stack(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if (a)
		{
			ft_putnbr(a->num);
			a = a->next;
		}
		else
			ft_putchar(' ');
		ft_putchar(' ');
		if (b)
		{
			ft_putnbr(b->num);
			b = b->next;
		}
		else
			ft_putchar(' ');
		ft_putchar('\n');
	}
	ft_putstr("- -\n");
	ft_putstr("a b\n");
}

int			is_sorted(t_stack *a, t_stack *b)
{
	t_stack *tmp;

	tmp = a;
	if (b != NULL)
		return (0);
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

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
	len = stack_len((*stack)) - 1;
	while (i < len)
	{
		if ((*stack)->num > (*stack)->next->num)
		{
			sa(stack);
		}
		ra(stack);
		i++;
	}
	ra(stack); //ошибка
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
	int		i;
	int		len;

	i = 0;
	if (argc < 2)
		exit(-1);
	a = create_stack(argc, argv);
	b = NULL;
	len = stack_len(a);
	while (i < len / 2)
	{
		pb(&a, &b);
		i++;
	}
	
	bubble_sort_high(&a);
	bubble_sort_low(&b);
	
	ft_putchar('\n');
	print_stack(a, b);
	delete_stack(&a);
	return (0);
}