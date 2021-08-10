/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:39:47 by ancoulon          #+#    #+#             */
/*   Updated: 2021/08/10 11:57:27 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"

#include <stdio.h>

void	ps_stack4(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	int64_t	val;
	size_t	i;

	val = st_a->data[st_a->len - 1];
	inst_save("pb", insts, st_a, st_b);
	ps_stack3(st_a, st_b, insts);
	i = 0;
	while (i < 3)
	{
		if (st_a->data[st_a->len - 1] > val)
			break;
		inst_save("ra", insts, st_a, st_b);
		i++;
	}
	inst_save("pa", insts, st_a, st_b);
	while (i > 0)
	{
		inst_save("rra", insts, st_a, st_b);
		i--;
	}
}

static size_t	find_loc(t_stack *st_a, t_stack *st_b, t_llst **insts, size_t rot)
{
	size_t	i;

	i = 0;
	while (i < 3 - rot)
	{
		if (st_a->data[st_a->len - 1] > st_b->data[st_b->len - 1])
			break;
		inst_save("ra", insts, st_a, st_b);
	}
	inst_save("pa", insts, st_a, st_b);
	return (i);
}

void	ps_stack5(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	size_t	i;
	size_t	j;
	size_t	tot_rot;

	inst_save("pb", insts, st_a, st_b);
	inst_save("pb", insts, st_a, st_b);
	if (st_b->data[st_b->len - 2] < st_b->data[st_b->len - 1])
		inst_save("sb", insts, st_a, st_b);
	ps_stack3(st_a, st_b, insts);
	i = find_loc(st_a, st_b, insts, 0);
	stack_print(st_a, st_b);
	j = find_loc(st_a, st_b, insts, i);
	tot_rot = i + j + 1;
	while (tot_rot > 0)
	{
		inst_save("rra", insts, st_a, st_b);
		tot_rot--;
	}
	stack_print(st_a, st_b);
}

