/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:39:47 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/11 17:33:51 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

static int rotate_stack(t_stack *st_a, t_stack *st_b, t_llst **insts, int64_t target)
{
	size_t	i;
	size_t	len;
	int		br;

	i = 0;
	len = st_a->len;
	br = 0;
	if (st_a->data[0] <= target) // case 1: target > biggest element of stack a
	{
		if (inst_save("pa", insts, st_a, st_b))
			return (1);
		if (inst_save("ra", insts, st_a, st_b))
			return (1);
	}
	else if (st_a->data[st_a->len - 1] >= target) // case 2: target < smallest element of stack a
	{
		if (inst_save("pa", insts, st_a, st_b))
			return (1);
	}
	else // TODO: case 3: target inside the stack a, iterate in stack to find the index of target
	{
		while (i < len - 1 && !(st_a->data[i] <= target))
			i++;
		while (i-- > 0)
			if (inst_save("rra", insts, st_a, st_b))
			return (1);
		if (inst_save("pa", insts, st_a, st_b))
			return (1);
	}
	return (0);
}

int	ps_stack5(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	size_t	push;
	size_t	i;

	push = st_a->size - 3;
	i = 0;
	while (i++ < push)
		if (inst_save("pb", insts, st_a, st_b))
			return (1);
	if (ps_stack3(st_a, st_b, insts))
		return (1);
	i = 0;
	while (i++ < push)
	{
		if (rotate_stack(st_a, st_b, insts, st_b->data[st_b->len - 1]))
			return (1);
		if (inst_save("pa", insts, st_a, st_b))
			return (1);
	}
	return (0);
}

