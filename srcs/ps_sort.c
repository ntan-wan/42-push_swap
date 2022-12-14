/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:07:05 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/07 02:23:14 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stk *stack)
{
	while (stack && stack->next != NULL)
	{
		if (stack->index - stack->next->index > 0)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_push_3_left(t_stk **stk_a, t_stk **stk_b)
{
	int	size;

	size = stack_size(*stk_a);
	while (size-- > 3)
	{
		do_push(stk_a, stk_b);
		ft_putstr_fd("pb\n", 1);
	}
}

void	sort_3(t_stk **stack)
{
	int		pos;
	t_stk	*ptr;
	int		index;
	int		highest;

	highest = find_highest_index(*stack);
	while (!is_sorted(*stack))
	{
		ptr = *stack;
		init_pos(*stack);
		while (ptr)
		{
			pos = ptr->pos;
			index = ptr->index;
			if (pos == 1 && index == highest)
				do_and_print(stack, do_rotate_right, "rra\n");
			if (pos == 0 && index == highest)
				do_and_print(stack, do_rotate_left, "ra\n");
			else if (pos == 0 && index > ptr->next->index)
				do_and_print(stack, do_swap, "sa\n");
			ptr = ptr->next;
		}
	}
}
