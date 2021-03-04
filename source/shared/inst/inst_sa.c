/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_sa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:40:04 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/04 21:18:18 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	inst_sa(t_stack *st_a, t_stack *st_b)
{
	int64_t	tmp;

	(void)st_b;
	if (st_a->len < 2)
		return ;
	tmp = st_a->data[st_a->len - 1];
	st_a->data[st_a->len - 1] = st_a->data[st_a->len - 2];
	st_a->data[st_a->len - 2] = tmp;
}
