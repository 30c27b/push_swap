/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 20:58:10 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/04 21:02:51 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "shared.h"
#include "carbon/str.h"

int		sh_interpreter(t_llst *insts, t_stack *st_a, t_stack *st_b)
{
	t_llst	*node;
	t_inst	inst;

	node = insts;
	while (node)
	{
		if (str_len(node->data) > 0)
		{
			inst = inst_get(node->data);
			if (!inst.name)
				return (1);
			inst.exec(st_a, st_b);
		}
		node = node->next;
	}
	return (0);
}
