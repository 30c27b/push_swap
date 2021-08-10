/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:50:51 by ancoulon          #+#    #+#             */
/*   Updated: 2021/08/10 10:54:50 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"

void	ps_process(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	if (st_a->len <= 1)
		return ;
	else if (st_a->len == 2)
	{
		if (st_a->data[1] > st_a->data[0])
			inst_save("sa", insts, st_a, st_b);
	}
	else if (st_a->len == 3)
		ps_stack3(st_a, st_b, insts);
	else if (st_a->len == 4)
		ps_stack4(st_a, st_b, insts);
	else if (st_a->len == 5)
		ps_stack5(st_a, st_b, insts);
	else
		ps_stack100(st_a, st_b, insts);
}
