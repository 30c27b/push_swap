/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:45:00 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/13 15:15:17 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

static size_t	chunk_calculator(size_t size)
{
	size_t	chunk_size;

	chunk_size = size / 20;
	return (chunk_size);
}

static void	scan_stack(t_stack *st_a, size_t chunk, size_t chunk_size)
{
	int64_t	hold_first;
	int64_t	hold_second;
	size_t	i;

	i = 0;
	while (i++ < st_a->len)
	{
		if (st_a->data[i] >= chunk_size * chunk && st_a->data[i] < chunk_size * (chunk + 1))
		{
			hold_first = i;
			i = st_a->len;
		}
	}
	i = st_a->len;
	while (i-- > 0)
	{
		if (st_a->data[i - 1] >= chunk_size * chunk && st_a->data[i - 1] < chunk_size * (chunk + 1))
		{
			hold_second = i - 1;
			i = 0;
		}
	}
	// TODO: check easyest holded number to push to stack b
}

void	ps_stack100(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	size_t	chunk_size;
	size_t	chunk_nbr;
	size_t	i;

	(void)st_a;
	(void)st_b;
	(void)insts;
	chunk_size = chunk_calculator(st_a->size);
	chunk_nbr = st_a->size / chunk_size;
	i = 0;
	while (i < chunk_nbr)
	{
		scan_stack(st_a, i, chunk_size);
		i++;
	}
}
