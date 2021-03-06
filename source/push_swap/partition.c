/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:15:02 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/06 13:05:58 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include "carbon/mem.h"
#include "carbon/llst.h"

int		ps_partition_mark(t_llst **lst, size_t n)
{
	size_t	*data;
	t_llst	*node;

	data = mem_calloc(sizeof(size_t));
	if (!data)
		return (1);
	*data = n;
	node = llst_new(data);
	if (!node)
		return (1);
	llst_push(lst, node);
	return (0);
}

int		ps_partition_exists(t_llst **lst, size_t n)
{
	t_llst	*node;

	node = *lst;
	while (node)
	{
		if (*(size_t *)node->data == n)
			return (1);
		node = node->next;
	}
	return (0);
}
