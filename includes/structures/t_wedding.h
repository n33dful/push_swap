/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_wedding.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:52:10 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/08 20:26:53 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WEDDING_H
# define T_WEDDING_H

/*
** **************************** Structure Includes *****************************
*/

# include "t_elem.h"
# include "t_list.h"

/*
** *************************** Structure Definition ****************************
*/

typedef struct	s_wedding
{
	char		best_mode;
	int			turns_compare[4];
	t_elem		*elem;
	t_list		*stack;
}				t_wedding;

/*
** *****************************************************************************
*/

#endif