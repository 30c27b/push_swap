/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:39:47 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/13 13:51:53 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

void	ps_stack3(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	if (st_a->data[2] > st_a->data[1] && st_a->data[1] > st_a->data[0])
	{
		inst_save("sa", insts, st_a, st_b);
		inst_save("rra", insts, st_a, st_b);
	}
	else if (st_a->data[2] > st_a->data[0] && st_a->data[1] < st_a->data[0])
		inst_save("ra", insts, st_a, st_b);
	else if (st_a->data[0] > st_a->data[2] && st_a->data[1] < st_a->data[2])
		inst_save("sa", insts, st_a, st_b);
	else if (st_a->data[1] > st_a->data[0] && st_a->data[2] < st_a->data[0])
	{
		inst_save("sa", insts, st_a, st_b);
		inst_save("ra", insts, st_a, st_b);
	}
	else if (st_a->data[1] > st_a->data[2] && st_a->data[0] < st_a->data[2])
		inst_save("rra", insts, st_a, st_b);
}
