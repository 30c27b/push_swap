/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:12:59 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/19 13:51:08 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"
# include "carbon/llst.h"
# include <stddef.h>
# include <stdint.h>

typedef struct s_bigchunkus
{
	size_t	chunk_nbr;
	size_t	chunk_size;
	size_t	chunk;
	int64_t	*sorted_stack;
	size_t	size;
	int64_t	max;
	long long	hold[2];
	size_t	target;
}	t_bigchunkus;

void	ps_process(t_stack *st_a, t_stack *st_b, t_llst **insts);

void	ps_stack3(t_stack *st_a, t_stack *st_b, t_llst **insts);

void	ps_stack5(t_stack *st_a, t_stack *st_b, t_llst **insts);

void	ps_stack100(t_stack *st_a, t_stack *st_b, t_llst **insts);

size_t	chunk_calculator(size_t size);

int64_t	*sort_stack(t_stack *stack);

void	ps_print_insts(t_llst *insts);

#endif
