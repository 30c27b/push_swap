/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:13:53 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/04 21:14:51 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "shared.h"
#include "carbon/fmt.h"

int		main(int argc, char **argv)
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
	insts = sh_reader();
	if (!insts)
		return (print_error());
	if (sh_interpreter(insts, st_a, st_b))
		return (print_error());
	if (sh_inspector(st_a, st_b))
		fmt_println("KO");
	else
		fmt_println("OK");
	stack_free(st_a);
	stack_free(st_b);
}
