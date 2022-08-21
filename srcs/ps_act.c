/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_act.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:29:11 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/22 03:20:43 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	act_rotate(t_stack **stack, t_stack *target)
{
	int	size;

	size = stack_size(*stack);
	while (*stack != target)
	{
		if (target->pos <= size / 2)
			do_ra(stack);
		else if (target->pos > size / 2)
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

void	act_sort_stacks(t_stack **stack_a, t_stack **stack_b, int max_index)
{
	(void)max_index;
	//init_pos(*stack_a);
	find_target_pos_b(stack_a, stack_b, max_index);
	calc_cost(stack_a, 0);
	calc_cost(stack_b, 1);
}