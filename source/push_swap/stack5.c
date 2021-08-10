/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:39:47 by ancoulon          #+#    #+#             */
/*   Updated: 2021/08/10 14:22:29 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdlib.h>

static size_t	value_index(int64_t	*sorted, size_t sorted_size, int64_t val)
{
	size_t	i;

	i = 0;
	while (i < sorted_size)
	{
		if (sorted[i] == val)
			return (i);
		i++;
	}
	error_exit();
	return (0);
}

void	ps_stack4(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	int64_t	*sorted;
	size_t	sorted_size;
	size_t	to_sort;
	size_t	i;

	sorted = sort_stack(st_a);
	sorted_size = st_a->len;
	inst_save("pb", insts, st_a, st_b);
	to_sort = value_index(sorted, sorted_size, st_b->data[st_b->len - 1]);
	ps_stack3(st_a, st_b, insts);
	i = 0;
	while (i < 4)
	{
		if (i == to_sort)
			inst_save("pa", insts, st_a, st_b);
		i++;
		inst_save("ra", insts, st_a, st_b);
	}
	free(sorted);
}

void	ps_stack5(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	int64_t	*sorted;
	size_t	sorted_size;
	size_t	to_sort[2];
	size_t	i;

	sorted = sort_stack(st_a);
	sorted_size = st_a->len;
	inst_save("pb", insts, st_a, st_b);
	inst_save("pb", insts, st_a, st_b);
	if (st_b->data[st_b->len - 1] > st_b->data[st_b->len - 2])
		inst_save("sb", insts, st_a, st_b);
	to_sort[0] = value_index(sorted, sorted_size, st_b->data[st_b->len - 1]);
	to_sort[1] = value_index(sorted, sorted_size, st_b->data[st_b->len - 2]);
	ps_stack3(st_a, st_b, insts);
	i = 0;
	while (i < 5)
	{
		if (i == to_sort[0] || i == to_sort[1])
			inst_save("pa", insts, st_a, st_b);
		i++;
		inst_save("ra", insts, st_a, st_b);
	}
	free(sorted);
}
