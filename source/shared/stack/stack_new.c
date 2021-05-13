/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:09:00 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/13 12:41:01 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "carbon/mem.h"

t_stack	*stack_new(size_t size)
{
	t_stack	*stack;

	stack = mem_calloc(sizeof(t_stack));
	if (!stack)
		error_exit();
	stack->size = size;
	stack->len = 0;
	stack->data = mem_calloc(sizeof(int64_t) * size);
	if (!stack->data)
		error_exit();
	return (stack);
}
