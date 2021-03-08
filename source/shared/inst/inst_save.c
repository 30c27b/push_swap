/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_save.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:05:01 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 09:09:58 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "carbon/llst.h"

int		inst_save(char *inst, t_llst **insts, t_stack *st_a, t_stack *st_b)
{
	t_llst	*node;
	t_inst	in;
	
	node = llst_new(inst);
	if (!node)
		return (1);
	llst_push(insts, node);
	in = inst_get(inst);
	if (!in.name)
		return (1);
	in.exec(st_a, st_b);
	return (0);
}
