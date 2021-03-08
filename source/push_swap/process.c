/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:50:51 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 09:15:38 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

int		ps_process(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	size_t	i;

	i = 0;
	while (ps_sort(st_a, st_b, insts))
	{
		if (ps_splita(st_a, st_b, insts))
			return (1);
	}
	ps_bringb(st_a, st_b, insts);
	if (ps_sort(st_a, st_b, insts) || st_b->len > 0)
	{
		ps_process(st_a, st_b, insts);
		return (0);
	}
	else
		return (0);
}
