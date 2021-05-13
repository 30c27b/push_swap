/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:15:35 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/13 12:23:56 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include "carbon/llst.h"
#include "carbon/fmt.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;
	t_llst	*insts;

	if (argc < 2)
		return (1);
	st_a = stack_parse(argc, argv);
	if (!st_a)
		return (print_error());
	st_b = stack_new(st_a->size);
	if (!st_b)
		return (print_error());
	if (ps_process(st_a, st_b, &insts))
		return (print_error());
	ps_print_insts(insts);
	stack_free(st_a);
	stack_free(st_b);
	llst_destroyl(&insts, NULL);
	// stack_print(st_a, st_b);
	// if (ps_process(st_a, st_b, &insts))
	// 	return (print_error());
	// stack_print(st_a, st_b);
	// ps_print_insts(insts);
}
