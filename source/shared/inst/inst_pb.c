/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:14:59 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/06 15:16:55 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	inst_pb(t_stack *st_a, t_stack *st_b)
{
	if (st_a->len < 1)
		return ;
	st_b->data[st_b->len] = st_a->data[st_a->len - 1];
	st_a->data[st_a->len - 1] = 0;
	st_a->len -= 1;
	st_b->len += 1;
}
