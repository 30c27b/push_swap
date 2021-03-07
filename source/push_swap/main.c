/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:15:35 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/07 12:27:45 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include "carbon/llst.h"
#include "carbon/fmt.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;

	if (argc < 2)
		return (1);
	st_a = stack_parse(argc, argv);
	if (!st_a)
		return (print_error());
	st_b = stack_new(st_a->size);
	if (!st_b)
		return (print_error());
	stacks_print(st_a, st_b);
	printf("--------\n");
	ps_splita(st_a, st_b);
	printf("--------\n");
	printf("test1\n");
	stacks_print(st_a, st_b);
	printf("--------\n");
	ps_splita(st_a, st_b);
	printf("--------\n");
	stacks_print(st_a, st_b);
	printf("--------\n");
	ps_bringb(st_a, st_b);
	printf("--------\n");
	stacks_print(st_a, st_b);
	printf("--------\n");
	ps_bringb(st_a, st_b);
	printf("--------\n");
	stacks_print(st_a, st_b);
}
