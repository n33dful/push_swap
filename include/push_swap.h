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

void		ft_stack_divorce(t_data *data);

int			ft_stack_new(int argc, char **argv, t_data *data);
int			ft_stack_indexing(t_data *data);

int			ft_stack_command(int mode, const char *cmd, t_data *data);

int			ft_stack_markup(t_data *data);
void		ft_stack_markup_elem(int mode, t_list *stack);
void	    ft_stack_markup_head(t_data *data);
int			ft_stack_markup_amount(t_list *stack);

void    	del_stack_elem(void *content, size_t content_size);

#endif
