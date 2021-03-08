/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:11:15 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 09:19:10 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include "carbon/mem.h"
#include <stdlib.h>
#include <stdio.h>

static void	swap(int64_t *a, int64_t *b)
{
	int64_t	tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	sort_array(int64_t *arr, size_t len)
{
	int		sorted;
	size_t	i;

	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		i = 0;
		while (i < len - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]);
				sorted = 0;
			}
			i++;
		}
	}
}


int		ps_median(t_stack *st, size_t start, size_t end, int64_t *med)
{
	int64_t	*cpy;
	size_t	len;

	if (st->len == 0)
		return (0);
	len = end - start + 1;
	cpy = mem_calloc(sizeof(int64_t) * len);
	if (!cpy)
		return (1);
	mem_cpy(cpy, st->data + start, sizeof(int64_t) * len);
	sort_array(cpy, len);
	*med = cpy[((len + 1) / 2) - 1];
	free (cpy);
	return (0);
}
