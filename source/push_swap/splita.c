/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splita.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:21:56 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/07 12:20:57 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

int		ps_splita(t_stack *st_a, t_stack *st_b)
{
	int64_t	med;
	size_t	start;
	size_t	len;
	size_t	i;
	size_t	rot;
	
	start = stack_prtlast(st_a);
	if (ps_median(st_a, start, st_a->len - 1, &med))
		return (1);
	printf("med: %lld\n", med);
	if (st_b->len > 0 && stack_prtadd(st_b, st_b->len - 1))
		return (1);
	i = 0;
	rot = 0;
	len = st_a->len - start + 1;
	while (i < len)
	{
		if (st_a->data[st_a->len - 1] <= med)
			inst_pb(st_a, st_b);
		else
		{
			inst_ra(st_a, st_b);
			rot++;
		}
		i++;
	}
	if (start)
	{
		i = 0;
		while (i++ < rot)
			inst_rra(st_a, st_b);
	}
	return (0);
}
