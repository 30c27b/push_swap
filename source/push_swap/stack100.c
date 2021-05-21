/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:45:00 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/21 12:02:15 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include "carbon/str.h"
#include <stdio.h>

static void find_next(t_stack *st_a, t_stack *st_b, t_llst **insts,
t_bigchunkus *data)
{
	int64_t	next;
	size_t	i;
	size_t	next_i;
	size_t	rot;

	next = data->sorted_stack[data->size - st_a->len];
	i = st_b->len;
	next_i = 0;
	while (i > 0)
	{
		printf("???, i: %zu, next: %lld, data: %lld\n", i - 1, next, st_b->data[i - 1]);

		if (st_b->data[i - 1] == next)
		{
			next_i = i - 1;
			break;
		}
		i--;
	}
	i = 0;
	if (next_i > st_b->len / 2)
	{
		rot = st_b->len - next_i - 1;
		while (i++ < rot)
			inst_save("rb", insts, st_a, st_b);
	}
	else
	{
		rot = next_i + 1;
		while (i++ < rot)
			inst_save("rrb", insts, st_a, st_b);
	}
	inst_save("pa", insts, st_a, st_b);
}

static void	move_element(t_stack *st_a, t_stack *st_b, t_llst **insts,
t_bigchunkus *data)
{
	size_t	i;
	size_t	rot;
	char	*rot_type;

	if (data->target <= (st_a->len / 2))
	{
		rot = data->target + 1;
		rot_type = "rra";
	}
	else
	{
		rot = st_a->len - data->target - 1;
		rot_type = "ra";
	}
	i = 0;
	while (i++ < rot)
	{
		inst_save(rot_type, insts, st_a, st_b);
	}
	inst_save("pb", insts, st_a, st_b);
}

static void	find_element(t_stack *st_a, t_bigchunkus *data)
{
	size_t	i;

	i = 0;
	while (i < st_a->len)
	{
		if (st_a->data[i] < data->max)
		{
			data->hold[0] = i;
			break ;
		}
		i++;
	}
	i = st_a->len - 1;
	while (i > 0)
	{
		if (st_a->data[i] < data->max)
		{
			data->hold[1] = i;
			break ;
		}
		i--;
	}
}

static void	converge_chunk(t_stack *st_a, t_stack *st_b, t_llst **insts,
t_bigchunkus *data)
{
	while (st_a->len > 5)
	{
		data->hold[0] = -1;
		data->hold[1] = -1;
		find_element(st_a, data);
		if (data->hold[0] == -1 && data->hold[1] == -1)
			break;
		if (data->hold[0] == -1)
			data->target = data->hold[1];
		else if (data->hold[1] == -1)
			data->target = data->hold[0];
		else if ((unsigned long long)data->hold[0] <= st_a->len - data->hold[1])
			data->target = data->hold[0];
		else
			data->target = data->hold[1];
		move_element(st_a, st_b, insts, data);
	}
}

void	ps_stack100(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	t_bigchunkus	data;

	data.chunk_nbr = chunk_calculator(st_a->size);
	data.chunk_size = st_a -> size / data.chunk_nbr;
	data.sorted_stack = sort_stack(st_a);
	data.size = st_a->size;
	data.chunk = 0;

	while (data.chunk < data.chunk_nbr + 1 && st_a->len > 5)
	{
		data.max = data.sorted_stack[data.chunk_size * (data.chunk + 1)];
		converge_chunk(st_a, st_b, insts, &data);
		data.chunk++;
	}
	ps_stack5(st_a, st_b, insts);
	while (st_b->len > 0)
	{
		printf("next\n");
		find_next(st_a, st_b, insts, &data);
	}
}
