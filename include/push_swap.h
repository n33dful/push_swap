/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:59:38 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/16 11:11:48 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_stack
{
	int				num;
	int				index;
	int				markup;
	int				turns;
	struct s_stack	*next;
}					t_stack;

void				swap(t_stack **stack);
void				push(t_stack **stack1, t_stack **stack2);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);

t_stack				*ft_stacknew(int argc, char **argv);
void				ft_stackdel(t_stack **stack);
void				ft_stackprint(t_stack *a, t_stack *b);
int					ft_stacklen(t_stack *stack);
t_stack				*ft_stackcpy(t_stack *stack);
void				ft_turnsindex(t_stack **stacka, t_stack **stackb);
void				ft_divorce(t_stack **a, t_stack **b);

#endif
