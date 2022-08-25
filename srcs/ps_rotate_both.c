/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:26:41 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/25 18:00:29 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_both_left(t_stk **stack_a, t_stk **stack_b)
{
	do_rotate_left(stack_a, 0, 0);
	do_rotate_left(stack_b, 0, 0);
	ft_printf("rr ");
}

void	rotate_both_right(t_stk **stack_a, t_stk **stack_b)
{
	do_rotate_right(stack_a, 0, 0);
	do_rotate_right(stack_b, 0, 0);
	ft_printf("rrr ");
}