/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack100_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:03:03 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/21 10:40:54 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include "carbon/mem.h"
#include <stdio.h>

size_t	chunk_calculator(size_t size)
{
	size_t	chunk_nbr;

	if (size < 300) {
		chunk_nbr = 5;
	}
	else
	{
		chunk_nbr = 11;
	}
	return (chunk_nbr);
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
