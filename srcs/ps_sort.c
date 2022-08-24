/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:07:05 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/24 18:44:45 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next != NULL)
	{
		if (stack->index - stack->next->index > 0)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_left_3(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;

	pushed = 0;
	size = stack_size(*stack_a);
	while (size > 3 && pushed < size / 2)
	{
		if ((*stack_a)->index < size / 2)
		{
			do_push(stack_a, stack_b, 0, 1);
			pushed++;
			size--;
		}
		else
			do_rotate_left(stack_a, 1, 0);
	}
	while (size-- > 3)
		do_push(stack_a, stack_b, 0, 1);
}

void	sort_3(t_stack **stack)
{
	int		pos;
	int		index;
	int		highest;
	t_stack	*ptr;

	highest = find_highest(*stack);
	while (!is_sorted(*stack))
	{
		ptr = *stack;
		init_pos(*stack);
		while (ptr)
		{
			pos = ptr->pos;
			index = ptr->index;
			if (pos == 1 && index == highest)
				do_rotate_right(stack, 1, 0);
			if (pos == 0 && index == highest)
				do_rotate_left(stack, 1, 0);
			else if (pos == 0 && index > ptr->next->index)
				do_swap(stack, 1, 0);
			ptr = ptr->next;
		}
	}
}
