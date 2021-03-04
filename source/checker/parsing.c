/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:28:09 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/04 10:43:00 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "shared.h"
#include "carbon.h"

t_stack		*ch_parser(int argc, char **argv)
{
	t_stack	*stack;
	t_llst	*node;
	size_t	i;


	stack = mem_calloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	i = 0;
	return (stack);
}