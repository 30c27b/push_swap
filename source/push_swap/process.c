/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:50:51 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/11 12:17:54 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

int	ps_process(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	if (st_a->size <= 1)
		return (0);
	if (st_a->size == 2)
	{
		if (st_a->data[1] > st_a->data[0])
			return(inst_save("sa", insts, st_a, st_b));
		return (0);
	}
	if (st_a->size == 3)
		return (ps_stack3(st_a, st_b, insts));
	if (st_a->size <= 5)
		return (ps_stack5(st_a, st_b, insts));
	return (1);
}
