/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bringb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:10:26 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 09:18:20 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

int		ps_bringb(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	size_t	prt;
	size_t	i;

	i = st_b->len - 1;
	if (stack_prtadd(st_a, st_a->len - 1))
		return (1);
	prt = stack_prtpop(st_b);
	if (!prt)
		i++;
	while (i > prt)
	{
		inst_save("pa", insts, st_a, st_b);
		i--;
	}
	return (0);
}
