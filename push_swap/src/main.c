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
	ft_putchar('\n');
	ft_putstr("- -\n");
	ft_putstr("a b\n");
}

int			main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc < 2)
		exit(-1);
	a = create_stack(argc, argv);
	b = NULL;
	print_stack(a, b);
	return (0);
}