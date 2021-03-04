/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:13:53 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/04 10:38:36 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "shared.h"
#include "carbon.h"

int
	main(int argc, char **argv)
{
	t_stack	*input;

	if (argc < 2)
		return (1);
	input = ch_parser(argc, argv);
	if (!input)
		return (print_error());
}
