/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_prtadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:47:11 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:35:58 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "carbon/llst.h"

int		stack_prtadd(t_stack *st, size_t n)
{
	t_llst	*node;

	if (!n)
		return (0);
	node = llst_new((void *)n);
	if (!node)
		return (1);
	llst_push(&st->prts, node);
	return (0);
}
