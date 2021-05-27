/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:13:53 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/27 11:20:34 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "shared.h"
#include "carbon/llst.h"
#include "carbon/fmt.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;
	t_llst	*insts;

	if (argc < 2)
		return (1);
	st_a = stack_parse(argc, argv);
	st_b = stack_new(st_a->size);
	insts = sh_reader();
	sh_interpreter(insts, st_a, st_b);
	if (sh_inspector(st_a, st_b))
		fmt_println("KO");
	else
		fmt_println("OK");
	stack_free(st_a);
	stack_free(st_b);
}
