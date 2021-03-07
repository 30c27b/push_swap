/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:50:51 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/07 13:30:12 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

int		ps_process(t_stack *st_a, t_stack *st_b)
{
	size_t	i;

	i = 0;
	while (ps_sort(st_a, st_b))
	{
		if (ps_splita(st_a, st_b))
			return (1);
	}
	ps_bringb(st_a, st_b);
	if (ps_sort(st_a, st_b) || st_b->len > 0)
	{
		ps_process(st_a, st_b);
		return (0);
	}
	else
		return (0);
}
