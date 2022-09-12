/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 06:36:36 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/25 18:12:47 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_lowest_index(t_stk *stack)
{
	t_stk	*ptr;
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

int	find_highest_index(t_stk *stack)
{
	t_stk	*ptr;
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

int	find_target_index(t_stk **stk_a, t_stk *ptr_b)
{
	t_stk	*ptr_a;
	int		target_index;

	ptr_a = *stk_a;
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
		return (find_lowest_index(*stk_a));
}

t_stk	*find_target_i(t_stk **stack, int target_index)
{
	t_stk	*ptr;

	ptr = *stack;
	while (ptr && ptr->index != target_index)
		ptr = ptr->next;
	return (ptr);
}

t_stk	*find_target_c(t_stk **stack, int cost, int b)
{
	t_stk	*target;

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
