/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_save.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:05:01 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/21 10:41:14 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "carbon/llst.h"

void	inst_save(char *inst, t_llst **insts, t_stack *st_a, t_stack *st_b)
{
	t_llst	*node;
	t_inst	in;

	node = llst_new(inst);
	if (!node)
		error_exit();
	llst_push(insts, node);
	in = inst_get(inst);
	if (!in.name)
		error_exit();
	in.exec(st_a, st_b);
}
