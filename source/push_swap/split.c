/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:21:56 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/06 12:12:36 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

int		ps_split(t_stack *st_a, t_stack *st_b)
{
	int64_t	med;
	size_t	len;
	size_t	i;
	
	if (ps_median(st_a, 0, st_a->len, &med))
		return (1);
	i = 0;
	len = st_a->len;
	while (i < len)
	{
		if (st_a->data[st_a->len - 1] <= med)
			inst_pb(st_a, st_b);
		else
			inst_ra(st_a, st_b);
		i++;
	}
	return (0);
}
