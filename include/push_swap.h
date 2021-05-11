/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:12:59 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/11 14:45:37 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"
# include "carbon/llst.h"
# include <stddef.h>
# include <stdint.h>

int	ps_process(t_stack *st_a, t_stack *st_b, t_llst **insts);

int	ps_stack3(t_stack *st_a, t_stack *st_b, t_llst **insts);

int	ps_stack5(t_stack *st_a, t_stack *st_b, t_llst **insts);

int	ps_stack100(t_stack *st_a, t_stack *st_b, t_llst **insts);

void ps_print_insts(t_llst *insts);

#endif
