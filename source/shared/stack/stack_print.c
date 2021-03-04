/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:11:24 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/04 21:16:25 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "carbon/fmt.h"
#include <stddef.h>
#include <stdio.h>

void	stack_print(t_stack *stack)
{
	size_t	i;

	i = stack->len;
	printf("(%zu):\n", stack->len);
	while (i > 0)
	{
		printf("> %lld\n", stack->data[i - 1]);
		i--;
	}
}
