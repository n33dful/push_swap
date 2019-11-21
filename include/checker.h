/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:51:01 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/21 21:20:14 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "push_swap.h"

void	ft_stack_print(t_stack *a, t_stack *b);
void	ft_checker_stack_print(char *commands, t_stack **a, t_stack **b, int v);

#endif
