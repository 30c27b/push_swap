/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:35:23 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/13 12:37:40 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "carbon/fmt.h"
#include <unistd.h>
#include <stdlib.h>

int	error_exit(void)
{
	fmt_fprintln(STDERR_FILENO, "Error");
	exit(EXIT_FAILURE);
}
