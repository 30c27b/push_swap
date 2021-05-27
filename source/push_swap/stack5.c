/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:39:47 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/27 11:31:26 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

static void	rotate_stack(t_stack *st_a, t_stack *st_b, t_llst **insts,
int64_t target)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (st_a->data[0] <= target)
	{
		inst_save("pa", insts, st_a, st_b);
		inst_save("ra", insts, st_a, st_b);
	}
	else if (st_a->data[st_a->len - 1] >= target)
		inst_save("pa", insts, st_a, st_b);
	else
	{
		while (st_a->data[st_a->len - 1] < target)
		{
			i++;
			inst_save("ra", insts, st_a, st_b);
		}
		inst_save("pa", insts, st_a, st_b);
		while (j++ < i)
			inst_save("rra", insts, st_a, st_b);
	}
}

void	ps_stack5(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	size_t	push;
	size_t	i;

	push = st_a->len - 3;
	i = 0;
	while (i++ < push)
		inst_save("pb", insts, st_a, st_b);
	ps_stack3(st_a, st_b, insts);
	i = 0;
	while (i++ < push)
	{
		rotate_stack(st_a, st_b, insts, st_b->data[st_b->len - 1]);
	}
}
