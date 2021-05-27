/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack100_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:03:03 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/27 09:19:23 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include "carbon/mem.h"
#include <stdio.h>

size_t	move_top_difficulty(t_stack *stack, size_t index)
{
	if (index < stack->len / 2)
	{
		return (index + 1);
	}
	else
	{
		return (stack->len - index - 1);
	}
}

void	move_top(t_stack *st_a, t_stack *st_b, t_llst **insts, size_t index)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (index < st_b->len / 2)
	{
		len = index + 1;
		while (i++ < len)
			inst_save("rrb", insts, st_a, st_b);
	}
	else
	{
		len = (st_b->len - index - 1);
		while (i++ < len)
			inst_save("rb", insts, st_a, st_b);
	}
}

static void	bubble_sort(int64_t *arr, size_t size)
{
	int64_t	tmp;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int64_t	*sort_stack(t_stack *stack)
{
	int64_t	*sorted_stack;
	size_t	i;

	sorted_stack = mem_calloc(sizeof(int64_t) * stack->size);
	if (!sorted_stack)
		error_exit();
	i = 0;
	while (i < stack->size)
	{
		sorted_stack[i] = stack->data[i];
		i++;
	}
	bubble_sort(sorted_stack, stack->size);
	return (sorted_stack);
}
