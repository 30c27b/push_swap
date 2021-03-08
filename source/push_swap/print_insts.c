/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_insts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:11:14 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 09:14:15 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include "carbon/fmt.h"

void	ps_print_insts(t_llst *insts)
{
	t_llst	*node;

	node = insts;
	while (node)
	{
		fmt_println((char *)node->data);
		node = node->next;
	}
}
