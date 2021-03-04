/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:20:08 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/04 21:17:20 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	inst_ra(t_stack *st_a, t_stack *st_b)
{
	int64_t	tmp;
	size_t	i;

	(void)st_b;
	if (st_a->len < 2)
		return ;
	i = st_a->len;
	tmp = st_a->data[st_a->len - 1];
	while (i > 0)
	{
		st_a->data[i] = st_a->data[i - 1];
		i--;
	}
	st_a->data[0] = tmp;
}
