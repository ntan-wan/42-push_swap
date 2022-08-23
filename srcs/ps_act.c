/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_act.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:29:11 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/23 16:09:34 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	act_rotate(t_stack **stack, int cost, int b)
{
	t_stack	*target;

	target = *stack;
	while (target)
	{
		if (b)
		{
			if (target->cost_b == cost)
				break;
		}
		else if (target->cost_a == cost)
			break ;
		target = target->next;
	}
	while (*stack != target)
	{
		if (cost > 0)
			do_ra(stack);
		else
			do_rra(stack);
	}
}

void	act_pop_left_3(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;

	pushed = 0;
	size = stack_size(*stack_a);
	while (size > 3 && pushed < size / 2)
	{
		if ((*stack_a)->index < size / 2)
		{
			do_push(stack_a, stack_b);
			pushed++;
			size--;
		}
		else
			do_ra(stack_a);
	}
	while (size-- > 3)
		do_push(stack_a, stack_b);
}
