/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:13:15 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/04 12:35:27 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHARED_H
# define SHARED_H

# include <stddef.h>
# include <stdint.h>

/*
** STACK ********************************************************************* **
*/

typedef struct	s_stack
{
	int64_t	*data;
	size_t	size;
	size_t	len;
}				t_stack;

t_stack	*stack_new(size_t size);

t_stack	*stack_parse(int argc, char **argv);

void	stack_print(t_stack *stack);

void	stack_free(t_stack *stack);

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
