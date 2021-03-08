/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_prtpop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:37:46 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:46:40 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "carbon/llst.h"

size_t	stack_prtpop(t_stack *st)
{
	t_llst	*node;
	size_t	ret;

	node = llst_pop(&st->prts);
	if (!node)
		return (0);
	ret = (size_t)node->data;
	llst_destroy(node, NULL);
	return (ret);
}
