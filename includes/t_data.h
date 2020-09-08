/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:53:24 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/08 20:24:53 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DATA_H
# define T_DATA_H

/*
** **************************** Structure Includes *****************************
*/

# include "t_list.h"
# include "t_markup.h"
# include "t_tree.h"

/*
** *************************** Structure Definition ****************************
*/

typedef struct	s_data
{
	char		exit_code;
	int			stack_a_len;
	int			stack_b_len;
	t_list		*sorted;
	t_list		*stack_a;
	t_list		*stack_b;
	t_markup	*by_index;
	t_markup	*by_number;
	t_markup	*chosen;
	t_tree		*tree;
}				t_data;

/*
** *****************************************************************************
*/

#endif
