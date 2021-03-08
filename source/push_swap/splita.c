/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splita.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:21:56 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 11:01:29 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

static int	get_median(t_stack *st_a, t_stack *st_b, int64_t *med,
size_t *start)
{
	*start = stack_prtlast(st_a);
	if (ps_median(st_a, *start, st_a->len - 1, med))
		return (1);
	if (st_b->len > 0 && stack_prtadd(st_b, st_b->len - 1))
		return (1);
	return (0);
}

static void	initializer(size_t *i, size_t *rot)
{
	*i = 0;
	*rot = 0;
}

int			ps_splita(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	int64_t	med;
	size_t	start;
	size_t	len;
	size_t	i;
	size_t	rot;

	if (get_median(st_a, st_b, &med, &start))
		return (1);
	initializer(&i, &rot);
	len = st_a->len - start + 1;
	while (i < len)
	{
		if (st_a->data[st_a->len - 1] <= med)
			inst_save("pb", insts, st_a, st_b);
		else
		{
			inst_save("ra", insts, st_a, st_b);
			rot++;
		}
		i++;
	}
	if (start)
		while (rot-- > 0)
			inst_save("rra", insts, st_a, st_b);
	return (0);
}
