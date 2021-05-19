/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:15:35 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/19 15:09:15 by ancoulon         ###   ########.fr       */
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
		exit(EXIT_SUCCESS);
	st_a = stack_parse(argc, argv);
	st_b = stack_new(st_a->size);
	ps_process(st_a, st_b, &insts);
	ps_print_insts(insts);
	stack_free(st_a);
	stack_free(st_b);
	llst_destroyl(&insts, NULL);
	// stack_print(st_a, st_b);
	// if (ps_process(st_a, st_b, &insts))
	// 	error_exit();
	// stack_print(st_a, st_b);
	// ps_print_insts(insts);
	exit(EXIT_SUCCESS);
}
