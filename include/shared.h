/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:13:15 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/27 12:36:32 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "carbon/llst.h"
# include <stddef.h>
# include <stdint.h>

typedef struct s_stack
{
	int64_t	*data;
	size_t	size;
	size_t	len;
}	t_stack;

typedef struct s_inst
{
	char	*name;
	void	(*exec)(t_stack *, t_stack *);
}	t_inst;

int		error_exit(void);

t_stack	*stack_new(size_t size);

t_stack	*stack_parse(int argc, char **argv);

void	stack_free(t_stack *stack);

t_inst	inst_get(char *name);

void	inst_save(char *inst, t_llst **insts, t_stack *st_a, t_stack *st_b);

void	inst_sa(t_stack *st_a, t_stack *st_b);

void	inst_sb(t_stack *st_a, t_stack *st_b);

void	inst_ss(t_stack *st_a, t_stack *st_b);

void	inst_pa(t_stack *st_a, t_stack *st_b);

void	inst_pb(t_stack *st_a, t_stack *st_b);

void	inst_ra(t_stack *st_a, t_stack *st_b);

void	inst_rb(t_stack *st_a, t_stack *st_b);

void	inst_rr(t_stack *st_a, t_stack *st_b);

void	inst_rra(t_stack *st_a, t_stack *st_b);

void	inst_rrb(t_stack *st_a, t_stack *st_b);

void	inst_rrr(t_stack *st_a, t_stack *st_b);

#endif
