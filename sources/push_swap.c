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

#include "push_swap.h"

//static void	ft_final_stack_rotation(t_list **stack_a)
//{
//	t_selem	*elem;
//	int		stack_len;
//
//	elem = (*stack_a)->content;
//	stack_len = (int)ft_lstlen((*stack_a));
//	while (elem->index != 0)
//	{
//		if (elem->index > stack_len / 2)
//		{
//			ft_stack_rotate(stack_a);
//			ft_putendl("ra");
//		}
//		else
//		{
//			ft_stack_reverse_rotate(stack_a);
//			ft_putendl("rra");
//		}
//		elem = (*stack_a)->content;
//	}
//}
//
//static char	*ft_findcomm(t_selem *stack)
//{
//	char	*res;
//	int		min;
//
//	res = NULL;
//	if (stack)
//	{
//		min = stack->turns;
//		res = stack->str;
//		while (stack)
//		{
//			if (stack->turns != 0 &&
//((stack->turns < 0 ? -1 * stack->turns : stack->turns) < min))
//			{
//				min = stack->turns;
//				res = stack->str;
//			}
//			stack = stack->next;
//		}
//	}
//	return (res);
//}
//
//static void	ft_base_algorithm(t_selem **a, t_selem **b)
//{
//	ft_stack_divorce(a, b);
//	while ((*b))
//	{
//		ft_countturns(a, b);
//		ft_putstr(ft_findcomm((*b)));
//		ft_instruction_execution(ft_findcomm((*b)), a, b);
//	}
//	ft_final_stack_rotation(a);
//}

static int	ft_program_completion(int code, t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		ft_lstdel(stack_a, del_stack_elem);
	if (stack_b)
		ft_lstdel(stack_b, del_stack_elem);
	if (code == -1)
		ft_putendl_fd("Error", 2);
	return (code);
}

int			main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	if (argc == 1)
		return (0);
	else if (!(stack_a = ft_stack_new(argc, argv)))
		return (ft_program_completion(-1, &stack_a, NULL));
	else if (!ft_stack_indexing(stack_a))
		return (ft_program_completion(-1, &stack_a, NULL));
	stack_b = NULL;
	if (!(ft_stack_divorce(&stack_a, &stack_b)))
		return (ft_program_completion(-1, &stack_a, &stack_b));
	//ft_stack_wedding(&stack_a, &stack_b);
	//ft_final_stack_rotation(&stack_a);
	return (ft_program_completion(0, &stack_a, &stack_b));
}
