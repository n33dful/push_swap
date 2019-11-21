/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:59:38 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/21 21:21:31 by cdarci           ###   ########.fr       */
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
	char			*str;
	int				keep;
	struct s_stack	*next;
}					t_stack;

void				ft_stack_swap(t_stack **stack);
void				ft_stack_push(t_stack **stack1, t_stack **stack2);
void				ft_stack_rotate(t_stack **stack);
void				ft_stack_reverse_rotate(t_stack **stack);

char				*ft_combine_instructions(char *first_inctrustion, \
					char *second_inctrustion);
void				ft_delete_array(char **arr);
void				ft_stack_indexind(t_stack **stack);

t_stack				*ft_stack_new(int argc, char **argv);
void				ft_stack_del(t_stack **stack);
int					ft_stack_len(t_stack *stack);
t_stack				*ft_stack_dup(t_stack *stack);
void				ft_stack_divorce(t_stack **a, t_stack **b);
void				ft_markup_head(t_stack **stack);
int					ft_markup_count(t_stack *stack);
void				ft_markup(t_stack **stack);
char				*ft_stack_a_instructions(t_stack **stacka, \
					t_stack **stackb);
char				*ft_stack_b_instructions(int count);
void				ft_countturns(t_stack **stacka, t_stack **stackb);
void				ft_instruction_execution(char *commands, \
					t_stack **a, t_stack **b);
char				*ft_inctruction_optimization(char *comma, char *commb);

#endif
