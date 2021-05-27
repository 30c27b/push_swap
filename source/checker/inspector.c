/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:06:41 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/27 11:20:26 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "shared.h"

int	sh_inspector(t_stack *st_a, t_stack *st_b)
{
	size_t	i;

	if (st_b->len > 0)
		return (1);
	i = 0;
	while (i < st_a->size - 1)
	{
		if (st_a->data[i] < st_a->data[i + 1])
			return (1);
		i++;
	}
	return (0);
}
