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

# include "../lib/incl/libft.h"
# include "push_swap_strusts.h"

int			ft_stack_new(int argc, char **argv, t_data *data);

int			ft_stack_indexing(t_data *data);

int	        ft_stack_markup_amount(t_list *stack);
void		ft_stack_markup_elem(int mode, t_list *stack);
void	    ft_stack_markup_head(t_data *data);
int			ft_stack_markup(t_data *data);

void		ft_stack_divorce(t_data *data);

void		ft_stack_wedding_update(t_data *data);
void		ft_stack_wedding_markup_elem(int compare[4], t_selem *stack_elem);
void		ft_stack_wedding_markup(t_data *data);
void		ft_stack_wedding_elem(t_selem *stack_elem, t_data *data);
void		ft_stack_wedding(t_data *data);

int			ft_stack_rotation(int mode, const char *cmd, t_data *data);

void    	ft_stack_elem_del(void *content, size_t content_size);

void	    ft_data_struct_init(t_data *data);
void	    ft_data_struct_del(t_data *data);

#endif
