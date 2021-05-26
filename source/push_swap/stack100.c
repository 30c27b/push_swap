/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:45:00 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/26 18:25:59 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include "carbon/str.h"
#include <stdio.h>

static void	find_edge(t_stack *st_a, t_stack *st_b, t_llst **insts, t_chunks *data)
{
	size_t	i;
	size_t	min;
	size_t	max;

	(void)st_a;
	(void)insts;
	(void)data;
	min = 0;
	max = 0;
	i = 0;
	while (i < st_b->len)
	{
		if (st_b->data[i] < st_b->data[min])
			min = i;
		if (st_b->data[i] > st_b->data[max])
			max = i;
		i++;
	}
	printf("min: %lld (index %zu). difficulty: %zu\n", st_b->data[min], min, move_top_difficulty(st_b, min));
	printf("max: %lld (index %zu). difficulty: %zu\n", st_b->data[max], max, move_top_difficulty(st_b, max));
	if (move_top_difficulty(st_b, min) > move_top_difficulty(st_b, max))
		move_top(st_a, st_b, insts, max);
	else
		move_top(st_a, st_b, insts, min);
}

static void	move_chunk_to_b(t_stack *st_a, t_stack *st_b, t_llst **insts, t_chunks *data)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = st_a->len;
	while (i < len)
	{
		if (st_a->data[st_a->len - 1] >= data->sorted[data->current_min] && st_a->data[st_a->len - 1] < data->sorted[data->current_max])
			inst_save("pb", insts, st_a, st_b);
		else
			inst_save("ra", insts, st_a, st_b);
		i++;
	}
}

void	ps_stack100(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	t_chunks	data;

	(void)insts;
	(void)st_b;
	data.sorted = sort_stack(st_a);
	data.size = st_a->size;
	data.chunks = 5;
	if (data.size % data.chunks == 0)
		data.chunks_size = data.size / data.chunks;
	else
		data.chunks_size = data.size / (data.chunks - 1);

	// printf("chunks: %zu\n", data.chunks);
	// printf("chunk size: %zu\n\n", data.chunks_size);

	data.current = 0;
	while (data.current < data.chunks)
	{
		data.current_max = data.chunks_size * (data.current + 1);
		if (data.current_max > data.size -1)
			data.current_max = data.size -1;
		data.current_min = data.chunks_size * data.current;
		data.current++;
		move_chunk_to_b(st_a, st_b, insts, &data);
		find_edge(st_a, st_b, insts, &data);
		break;
	}
}
