/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:17:00 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/04 21:18:26 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	inst_rra(t_stack *st_a, t_stack *st_b)
{
	int64_t	tmp;
	size_t	i;

	(void)st_b;
	if (st_a->len < 2)
		return ;
	i = 0;
	tmp = st_a->data[0];
	while (i < st_a->len - 1)
	{
		st_a->data[i] = st_a->data[i + 1];
		i++;
	}
	st_a->data[st_a->len - 1] = tmp;
}
