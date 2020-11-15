/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_elem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:49:50 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/08 20:25:48 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ELEM_H
# define T_ELEM_H

/*
** *************************** Structure Definition ****************************
*/

typedef struct		s_elem
{
	char			in_stack_a;
	char			in_stack_b;
	char			keep;
	char			wedding_mode;
	int				common_turns;
	int				index;
	int				number;
	int				reverse_rotates_to_top;
	int				rotates_to_top;
	int				total_turns;
	struct s_elem	*elem_after;
}					t_elem;

/*
** *****************************************************************************
*/

#endif
