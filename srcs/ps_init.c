/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 08:31:17 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/25 16:13:50 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_index(t_stack *stack, int size)
{
	int		value;
	t_stack	*highest;
	t_stack	*ptr;

	while (size--)
	{
		value = INT_MIN;
		highest = NULL;
		ptr = stack;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}

void	init_pos(t_stack *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->pos = pos;
		stack = stack->next;
		pos++;
	}
}

void	init_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*ptr_a;
	t_stack	*ptr_b;

	ptr_b = *stack_b;
	while (ptr_b)
	{
		ptr_a = find_target_i(stack_a, find_target_index(stack_a, ptr_b));
		ptr_b->target_pos = ptr_a->pos;
		ptr_b = ptr_b->next;
	}
}