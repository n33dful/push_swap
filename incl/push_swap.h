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
	struct s_stack	*next;
}					t_stack;

void				sa(t_stack **stack);
void				sb(t_stack **stack);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

t_stack				*create_stack(int argc, char **argv);
void				delete_stack(t_stack **stack);
void				print_stack(t_stack *a, t_stack *b);

#endif