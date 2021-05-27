/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:06:16 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/27 11:09:34 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

void	check_duplicates(t_stack *stack)
{
	int64_t	*sorted;
	size_t	i;

	sorted = sort_stack(stack);
	i = 0;
	while (i < stack->len - 1)
	{
		if (sorted[i] == sorted[i + 1])
			error_exit();
		i++;
	}
}
