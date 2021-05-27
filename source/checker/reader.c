/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:47:38 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/27 11:20:54 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "shared.h"
#include "carbon/llst.h"
#include "carbon/io.h"
#include <unistd.h>

t_llst	*sh_reader(void)
{
	t_llst	*head;
	t_llst	*node;
	char	*line;

	head = NULL;
	while (io_next_line(STDIN_FILENO, &line) > 0)
	{
		node = llst_new(line);
		if (!node)
			error_exit();
		llst_push(&head, node);
	}
	node = llst_new(line);
	if (!node)
		error_exit();
	llst_push(&head, node);
	return (head);
}
