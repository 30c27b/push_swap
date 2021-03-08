/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_isprt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:55:16 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:35:49 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int		stack_isprt(t_stack *st, size_t n)
{
	t_llst	*node;

	node = st->prts;
	while (node)
	{
		if ((size_t)node->data == n)
			return (1);
		node = node->next;
	}
	return (0);
}
