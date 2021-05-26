/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:45:00 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/26 12:38:47 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include "carbon/str.h"
#include <stdio.h>

static void	move_chunk(t_stack *st_a, t_stack *st_b, t_llst **insts, t_chunks *data)
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

	printf("chunks: %zu\n", data.chunks);
	printf("chunk size: %zu\n\n", data.chunks_size);

	data.current = 0;
	while (data.current < data.chunks)
	{
		data.current_max = data.chunks_size * (data.current + 1);
		if (data.current_max > data.size -1)
			data.current_max = data.size -1;
		data.current_min = data.chunks_size * data.current;
		data.current++;
		move_chunk(st_a, st_b, insts, &data);
		break;
	}
}
