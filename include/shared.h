/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:13:15 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/04 10:37:59 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHARED_H
# define SHARED_H

# include "carbon/llst.h"

typedef struct	s_stack
{
	t_llst	lst;
}				t_stack;

/*
** UTILS ******************************************************************** **
*/

int		print_error(void);

/*
** STACK INSTRUCTIONS ******************************************************* **
*/

void	inst_sa(t_stack *st1, t_stack *st2);

void	inst_sb(t_stack *st1, t_stack *st2);

void	inst_ss(t_stack *st1, t_stack *st2);

void	inst_pa(t_stack *st1, t_stack *st2);

void	inst_pb(t_stack *st1, t_stack *st2);

void	inst_ra(t_stack *st1, t_stack *st2);

void	inst_rb(t_stack *st1, t_stack *st2);

void	inst_rr(t_stack *st1, t_stack *st2);

void	inst_rra(t_stack *st1, t_stack *st2);

void	inst_rrb(t_stack *st1, t_stack *st2);

void	inst_rrr(t_stack *st1, t_stack *st2);

#endif
