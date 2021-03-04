/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rrb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:22:29 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/04 15:22:38 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	inst_rrb(t_stack *st_a, t_stack *st_b)
{
	int64_t	tmp;
	size_t	i;

	(void)st_a;
	if (st_b->len < 2)
		return ;
	i = 0;
	tmp = st_b->data[0];
	while (i < st_b->len -1)
	{
		st_b->data[i] = st_b->data[i + 1];
		i++;
	}
	st_b->data[st_b->len - 1] = tmp;
}