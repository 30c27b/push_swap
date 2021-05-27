/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:32:17 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/27 11:31:38 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "carbon/str.h"

t_inst	inst_get(char *name)
{
	static t_inst	tab[11] = {
		{"sa", &inst_sa}, {"sb", &inst_sb}, {"ss", &inst_ss},
		{"pa", &inst_pa}, {"pb", &inst_pb}, {"ra", &inst_ra},
		{"rb", &inst_rb}, {"rr", &inst_rr}, {"rra", &inst_rra},
		{"rrb", &inst_rrb}, {"rrr", &inst_rrr}};
	size_t			i;

	i = 0;
	while (i < 11)
	{
		if (!str_cmp(name, tab[i].name))
			return (tab[i]);
		i++;
	}
	return ((t_inst){NULL, NULL});
}
