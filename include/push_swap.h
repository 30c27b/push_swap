/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:12:59 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/27 12:40:31 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"
# include "carbon/llst.h"
# include <stddef.h>
# include <stdint.h>
# include <sys/types.h>

typedef struct s_chunks
{
	int64_t	*sorted;
	size_t	size;
	size_t	chunks;
	size_t	chunks_size;
	size_t	current;
	size_t	current_min;
	size_t	current_max;
}	t_chunks;

int		is_sorted(t_stack *stack);

void	check_duplicates(t_stack *stack);

void	ps_process(t_stack *st_a, t_stack *st_b, t_llst **insts);

void	ps_stack3(t_stack *st_a, t_stack *st_b, t_llst **insts);

void	ps_stack5(t_stack *st_a, t_stack *st_b, t_llst **insts);

void	ps_stack100(t_stack *st_a, t_stack *st_b, t_llst **insts);

int64_t	*sort_stack(t_stack *stack);

size_t	move_top_difficulty(t_stack *stack, size_t index);

void	move_top(t_stack *st_a, t_stack *st_b, t_llst **insts, size_t index);

void	ps_print_insts(t_llst *insts);

#endif
