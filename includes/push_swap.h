/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:59:38 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/08 20:30:29 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** ***************************** External Includes *****************************
*/

# include "basic.h"

/*
** ****************** Functions For Working With Stack Markup ******************
*/

int		ft_stack_markup_amount(t_list *stack);
int		ft_stack_markup(t_data *data);
void	ft_stack_markup_elem(char mode, t_list *stack);
void	ft_stack_markup_head(t_data *data);

/*
** ****************** Function For Working With Stack Divorce ******************
*/

void	ft_stack_divorce(t_data *data);

/*
** ***************** Functions For Working With Stack Wedding ******************
*/

void	ft_stack_wedding_elem(t_elem *elem, t_data *data);
void	ft_stack_wedding_markup_elem(int compare_modes[4], t_elem *elem);
void	ft_stack_wedding_markup(t_data *data);
void	ft_stack_wedding(t_data *data);

/*
** *****************************************************************************
*/

#endif
