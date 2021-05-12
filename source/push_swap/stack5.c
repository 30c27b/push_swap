/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:39:47 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/12 16:18:44 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

static int rotate_stack(t_stack *st_a, t_stack *st_b, t_llst **insts, int64_t target)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = st_a->len;
	printf("===========\nrotate_stack starts with target %llu\n----------\n", target);
	stack_print(st_a, st_b);
	printf("-----\n");
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
		// while (i < len - 1 && !(st_a->data[st_a->len - i - 1] > target))
		// 	i++;
		// printf("i = %zu\n",i);
		// while (j++ < i)
		// {
		// 	printf("ra\n");
		// 	inst_save("ra", insts, st_a, st_b);
		// }
		// j = 0;
		while (st_a->data[st_a->len - 1] < target)
		{
			printf("rra\n");
			i++;
			inst_save("rra", insts, st_a, st_b);
		}
		if (inst_save("pa", insts, st_a, st_b))
			return (1);
		while (j++ < i + 1)
		{
			printf("ra\n");
			inst_save("ra", insts, st_a, st_b);
		}
	}
	printf("----\nrotate_stack ends with target %llu\n===========\n", target);
	stack_print(st_a, st_b);
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
	}
	return (0);
}

