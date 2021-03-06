/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:11:24 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/06 14:59:04 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "carbon/fmt.h"
#include <stddef.h>
#include <stdio.h>

void stacks_print(t_stack *st_a, t_stack *st_b)
{
	printf("stack A (%zu):\n>", st_a->len);
	for (size_t i = 0; i < st_a->len; i++)
	{
		printf(" %lld", st_a->data[i]);
		if (stack_isprt(st_a, i))
			printf(" |");
	}
	printf("\n");
	printf("stack B (%zu):\n>", st_b->len);
	for (size_t i = 0; i < st_b->len; i++)
	{
		printf(" %lld", st_b->data[i]);
		if (stack_isprt(st_b, i))
			printf(" |");
	}
	printf("\n");
}
