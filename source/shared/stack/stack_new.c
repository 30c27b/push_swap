/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:09:00 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/07 18:50:23 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "carbon/mem.h"

t_stack	*stack_new(size_t size)
{
	t_stack	*stack;

	stack = mem_calloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = size;
	stack->len = 0;
	stack->data = mem_calloc(sizeof(int64_t) * size);
	if (!stack->data)
		return (NULL);
	return (stack);
}
