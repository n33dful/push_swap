/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:16:20 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/05 20:59:45 by cdarci           ###   ########.fr       */
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

int			main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int		i;

	i = 0;
	if (argc < 2)
		exit(-1);
	a = create_stack(argc, argv);
	b = NULL;
	while (!is_sorted(a, b))
	{
		if (!a->next)
		{
			while (b)
			{
				pa(&a, &b);
				ft_putstr("pa\n");
				i++;
			}
		}
		else if (a->next && a->num <= a->next->num)
		{
			pb(&a, &b);
			ft_putstr("pb\n");
			i++;
		}
		else
		{
			ra(&a);
			ft_putstr("ra\n");
			i++;
		}
	}
	ft_putstr("Total commands: ");
	ft_putnbr(i);
	ft_putchar('\n');
	print_stack(a, b);
	delete_stack(&a);
	return (0);
}