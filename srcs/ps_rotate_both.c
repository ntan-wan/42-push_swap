/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:26:41 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/05 12:22:51 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_both_left(t_stk **stk_a, t_stk **stk_b)
{
	if (*stk_a)
		do_rotate_left(stk_a);
	if (*stk_b)
		do_rotate_left(stk_b);
}

void	rotate_both_right(t_stk **stk_a, t_stk **stk_b)
{
	if (*stk_a)
		do_rotate_right(stk_a);
	if (*stk_b)
		do_rotate_right(stk_b);
}

void	swap_both(t_stk **stk_a, t_stk **stk_b)
{
	if (*stk_a)
		do_swap(stk_a);
	if (*stk_b)
		do_swap(stk_b);
}
