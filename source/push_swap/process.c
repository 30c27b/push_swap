/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:50:51 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/06 13:46:12 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

void display_stack(t_stack *st_a, t_stack *st_b, t_llst *partitions)
{
	(void)partitions;
	printf("stack A (%zu):\n>", st_a->len);
	for (size_t i = 0; i < st_a->len; i++)
		printf(" %lld", st_a->data[i]);
	printf("\n");
	printf("stack B (%zu):\n>", st_b->len);
	for (size_t i = 0; i < st_b->len; i++)
	{
		printf(" %lld", st_b->data[i]);
		if (ps_partition_exists(&partitions, i))
			printf(" |");
	}
	printf("\n");
}

int		ps_process(t_stack *st_a, t_stack *st_b)
{
	t_llst	*partitions;
	size_t	i;

	i = 0;
	partitions = NULL;
	while (st_a->len > 3)
	{
		if (ps_split(st_a, st_b))
			return (1);
		ps_partition_mark(&partitions, st_b->len - 1);
	}
	display_stack(st_a, st_b, partitions);
	return (0);
}
