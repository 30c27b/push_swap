/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:45:00 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/19 14:25:37 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

static void	move_element(t_stack *st_a, t_stack *st_b, t_llst **insts,
t_bigchunkus *data)
{
	size_t	i;
	size_t	rot;
	char	*rot_type;

	if (data->target <= (st_a->len / 2))
	{
		printf("from bottom\n");
		rot = st_a->len;
		rot_type = "ra";
	}
	else
	{
		printf("from top\n");
		rot = st_a->len - data->target;
		rot_type = "rra";
	}
	i = 0;
	while (i++ < rot)
		inst_save(rot_type, insts, st_a, st_b);
	printf("rotations: %zu of type %s\n", rot, rot_type);
	printf("\n\n\nstack after rotates:\n");
	stack_print(st_a, st_b);
	printf("\n\n\n");
	inst_save("pb", insts, st_a, st_b);
	printf("\n\n\nstack after push:\n");
	stack_print(st_a, st_b);
	printf("\n\n\n");
}

static void	find_element(t_stack *st_a, t_bigchunkus *data)
{
	size_t	i;

	i = 0;
	while (i < st_a->len)
	{
		if (st_a->data[i] <= data->max)
		{
			data->hold[0] = i;
			printf("i: %zu, hold: %lld\n", i, data->hold[0]);
			break ;
		}
		i++;
	}
	i = st_a->len - 1;
	while (i > 0)
	{
		if (st_a->data[i] <= data->max)
		{
			data->hold[1] = i;
			printf("i: %zu, hold: %lld\n", i, data->hold[1]);
			break ;
		}
		i--;
	}
}

static void	converge_chunk(t_stack *st_a, t_stack *st_b, t_llst **insts,
t_bigchunkus *data)
{
	while (1)
	{
		data->hold[0] = -1;
		data->hold[1] = -1;
		printf("hold0 : %lld(%lld)\n", data->hold[0], st_a->data[data->hold[0]]);
		printf("hold1 : %lld(%lld)\n", data->hold[1], st_a->data[data->hold[1]]);
		find_element(st_a, data);
		printf("hold0 : %lld(%lld)\n", data->hold[0], st_a->data[data->hold[0]]);
		printf("hold1 : %lld(%lld)\n", data->hold[1], st_a->data[data->hold[1]]);
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
		printf("target = %zu\n", data->target);
		move_element(st_a, st_b, insts, data);
		break;
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
	printf("sorted stack:\n");
	for (size_t i = 0; i < data.size; i++)
	{
		printf("%lld ", data.sorted_stack[i]);
	}
	printf("\n\n\n\n");

	printf("initial stack:\n");
	stack_print(st_a, st_b);
	printf("\n\n\n");
	printf("chunks: %zu\nchunk_size: %zu\n", data.chunk_nbr, data.chunk_size);
	while (data.chunk < data.chunk_nbr)
	{
		printf("max ind. : %zu\n", data.chunk_size * (data.chunk + 1));
		data.max = data.sorted_stack[data.chunk_size * (data.chunk + 1)];
		printf("max: %lld\n", data.max);
		converge_chunk(st_a, st_b, insts, &data);
		data.chunk++;
		break;
	}
}
