/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:59:38 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/23 16:23:09 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../library/incl/libft.h"
# include "push_swap_strusts.h"

int			ft_stack_divorce(t_list **stack_a, t_list **stack_b);

t_list		*ft_stack_new(int ac, char **av);
int			ft_stack_indexing(t_list *stack);

void		ft_stack_push(t_list **stack_from, t_list **stack_to);
void		ft_stack_rotate(t_list **stack);
void		ft_stack_reverse_rotate(t_list **stack);
void		ft_stack_swap(t_list **stack);
int			ft_stack_command(int mode, char *cmd, t_list **stack_a, t_list **stack_b);

t_markup	*ft_stack_markup(t_list **stack);
void		ft_stack_markup_head(t_markup *markup, t_list **stack);
void		ft_stack_markup_elem(int mode, t_list *stack);
int			ft_stack_markup_amount(t_list *stack);

void    	del_stack_elem(void *content, size_t content_size);

#endif
