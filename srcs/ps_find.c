/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 06:36:36 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/22 03:28:43 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_lowest(t_stack *stack)
{
	t_stack	*ptr;
	int		index;

	ptr = stack;
	index = INT_MAX;
	while (ptr)
	{
		if (ptr->index < index)
			index = ptr->index;
		ptr = ptr->next;
	}
	return (index);
}

int	find_highest(t_stack *stack)
{
	t_stack	*ptr;
	int		index;

	ptr = stack;
	index = INT_MIN;
	while (ptr)
	{
		if (ptr->index > index)
			index = ptr->index;
		ptr = ptr->next;
	}
	return (index);
}

void	find_target_pos_b(t_stack **stack_a, t_stack **stack_b, int max_index)
{
	int	i;
	t_stack *ptr_a;
	t_stack *ptr_b;

	ptr_b = *stack_b;
	init_pos(*stack_a);
	while (ptr_b)
	{
		i = 1;
		ptr_a = NULL;
		while (!ptr_a)
		{
			ptr_a = *stack_a;
			while (ptr_a && ptr_a->index - ptr_b->index != i)
				ptr_a = ptr_a->next;
			if (ptr_b->index == max_index)
			{
				ptr_a = *stack_a;
				while (ptr_a->index != find_lowest(*stack_a))
					ptr_a = ptr_a->next;
			}
			else
				i++;
		}
		ptr_b->target_pos = ptr_a->pos;
		ptr_b = ptr_b->next;
	}
}
