/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_sb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:55:26 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/04 21:18:31 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	inst_sb(t_stack *st_a, t_stack *st_b)
{
	int64_t	tmp;

	(void)st_a;
	if (st_b->len < 2)
		return ;
	tmp = st_b->data[st_b->len - 1];
	st_b->data[st_b->len - 1] = st_b->data[st_b->len - 2];
	st_b->data[st_b->len - 2] = tmp;
}
