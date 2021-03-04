/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:35:23 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/04 10:37:14 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "carbon/fmt.h"
#include <unistd.h>

int		print_error(void)
{
	fmt_fprintln(STDERR_FILENO, "Error");
	return (1);
}
