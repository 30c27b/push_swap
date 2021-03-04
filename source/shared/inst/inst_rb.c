/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:22:03 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/04 15:22:12 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	inst_rb(t_stack *st_a, t_stack *st_b)
{
	int64_t	tmp;
	size_t	i;

	(void)st_a;
	if (st_b->len < 2)
		return ;
	i = st_b->len;
	tmp = st_b->data[st_b->len - 1];
	while (i > 0)
	{
		st_b->data[i] = st_b->data[i - 1];
		i--;
	}
	st_b->data[0] = tmp;
}