/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 06:36:36 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/25 16:41:51 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_lowest_index(t_stack *stack)
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

int	find_highest_index(t_stack *stack)
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

int	find_target_index(t_stack **stack_a, t_stack *ptr_b)
{
	t_stack	*ptr_a;
	int		target_index;

	ptr_a = *stack_a;
	target_index = INT_MAX;
	while (ptr_a)
	{
		if (ptr_a->index > ptr_b->index && ptr_a->index < target_index)
				target_index = ptr_a->index;
		ptr_a = ptr_a->next;
	}
	if (target_index != INT_MAX)
		return (target_index);
	else
		return (find_lowest_index(*stack_a));
}

t_stack	*find_target_i(t_stack **stack, int target_index)
{
	t_stack	*ptr;

	ptr = *stack;
	while (ptr && ptr->index != target_index)
		ptr = ptr->next;
	return (ptr);
}

t_stack	*find_target_c(t_stack **stack, int cost, int b)
{
	t_stack	*target;

	target = *stack;
	while (target)
	{
		if (b)
		{
			if (target->cost_b == cost)
				break ;
		}
		else if (target->cost_a == cost)
			break ;
		target = target->next;
	}
	return (target);
}