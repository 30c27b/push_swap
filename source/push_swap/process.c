/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:50:51 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/06 18:36:34 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

int		ps_process(t_stack *st_a, t_stack *st_b)
{
	size_t	i;

	i = 0;
	while (st_a->len > 3)
	{
		if (ps_splita(st_a, st_b))
			return (1);
		stack_prtadd(st_b, st_b->len - 1);
	}
	ps_sort(st_a, st_b, st_a->len);
	return (0);
}
