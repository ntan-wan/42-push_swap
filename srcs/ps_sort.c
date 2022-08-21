/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:07:05 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/21 17:55:49 by ntan-wan         ###   ########.fr       */
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

void	sort_3(t_stack **stack)
{
	int		pos;
	int		index;
	t_stack	*ptr;
	int		highest;

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
				do_rra(stack);
			if (pos == 0 && index == highest)
				do_ra(stack);
			else if (pos == 0 && index > ptr->next->index)
				do_sa(stack);
			ptr = ptr->next;
		}
	}
}
