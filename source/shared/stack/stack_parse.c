/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:04:42 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/13 12:41:52 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "carbon.h"
#include <stdint.h>

static int	unsafe_input(char *s)
{
	size_t	i;

	i = 0;
	if (s[i] && (s[i] == '-' || s[i] == '+'))
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

t_stack	*stack_parse(int argc, char **argv)
{
	t_stack	*stack;
	size_t	i;

	stack = stack_new(argc - 1);
	i = 0;
	while (i < stack->size)
	{
		if (unsafe_input(argv[i + 1]))
			error_exit();
		stack->data[stack->size - i - 1] = types_str2int(argv[i + 1]);
		i++;
	}
	stack->len = stack->size;
	return (stack);
}
