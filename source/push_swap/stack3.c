/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:39:47 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/11 12:10:15 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

int	ps_stack3(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	// 321 -> 123
	if (st_a->data[2] > st_a->data[1] && st_a->data[1] > st_a->data[0])
	{
		printf("case 1\n");
		if (inst_save("sa", insts, st_a, st_b))
			return (1);
		if (inst_save("rra", insts, st_a, st_b))
			return (1);
	}
	// 312 -> 123
	else if (st_a->data[2] > st_a->data[0] && st_a->data[1] < st_a->data[0])
	{
		printf("case 2\n");
		if (inst_save("ra", insts, st_a, st_b))
			return (1);
	}
	// 213 -> 123
	else if (st_a->data[0] > st_a->data[2] && st_a->data[1] < st_a->data[2])
	{
		printf("case 3\n");
		if (inst_save("sa", insts, st_a, st_b))
			return (1);
	}
	// 132 -> 123
	else if (st_a->data[1] > st_a->data[0] && st_a->data[2] < st_a->data[0])
	{
		printf("case 4\n");
		if (inst_save("sa", insts, st_a, st_b))
			return (1);
		if (inst_save("ra", insts, st_a, st_b))
			return (1);
	}
	// 231 -> 123
	else if (st_a->data[1] > st_a->data[2] && st_a->data[0] < st_a->data[2])
	{
		printf("case 5\n");
		if (inst_save("rra", insts, st_a, st_b))
			return (1);
	}
	return (0);
}
