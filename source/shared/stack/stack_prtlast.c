/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_prtlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:20:43 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:46:44 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "carbon/llst.h"

size_t	stack_prtlast(t_stack *st)
{
	t_llst	*node;

	node = llst_tail(st->prts);
	if (!node)
		return (0);
	return ((size_t)node->data);
}
