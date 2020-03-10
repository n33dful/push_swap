/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_execution.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:55:00 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/21 20:38:26 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_what_to_do(char *comm, t_selem **a, t_selem **b)
{
	if (!ft_strcmp(comm, "sa") || !ft_strcmp(comm, "ss"))
		ft_stack_swap(a);
	if (!ft_strcmp(comm, "sb") || !ft_strcmp(comm, "ss"))
		ft_stack_swap(b);
	if (!ft_strcmp(comm, "pa"))
		ft_stack_push(b, a);
	if (!ft_strcmp(comm, "pb"))
		ft_stack_push(a, b);
	if (!ft_strcmp(comm, "ra") || !ft_strcmp(comm, "rr"))
		ft_stack_rotate(a);
	if (!ft_strcmp(comm, "rb") || !ft_strcmp(comm, "rr"))
		ft_stack_rotate(b);
	if (!ft_strcmp(comm, "rra") || !ft_strcmp(comm, "rrr"))
		ft_stack_reverse_rotate(a);
	if (!ft_strcmp(comm, "rrb") || !ft_strcmp(comm, "rrr"))
		ft_stack_reverse_rotate(b);
}

void		ft_instruction_execution(char *commands, t_selem **a, t_selem **b)
{
	char	**comm;
	int		i;

	i = 0;
	comm = ft_strsplit(commands, '\n');
	while (comm[i])
	{
		ft_what_to_do(comm[i], a, b);
		i++;
	}
	ft_arrdel(comm);
}
