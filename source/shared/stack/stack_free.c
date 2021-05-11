/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:07:09 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 11:03:18 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "carbon/llst.h"
#include <stdlib.h>

void	stack_free(t_stack *stack)
{
	if (stack)
	{
		if (stack->data)
			free(stack->data);
		if (stack->prts)
			llst_destroyl(&stack->prts, NULL);
		free(stack);
	}
}
