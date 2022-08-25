/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:07:05 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/25 10:33:06 by ntan-wan         ###   ########.fr       */
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
	/*t_stack	*ptr_top;
	t_stack	*ptr_bottom;
	int		size;
	int		pushed;
	int		i;

	size = stack_size(*stack_a);
	pushed = 0;
	i = 1;
	while (size > 3)
	{	
		ptr_top = *stack_a;
		utils_calc_cost(stack_a, 0);
		while (ptr_top)
		{
			if (ptr_top->index < (size / 2) * i)
				break ;
			ptr_top = ptr_top->next;
		}
		ptr_bottom = stack_find(*stack_a);
		while (ptr_bottom)
		{
			if (ptr_bottom->index < (size / 2) * i)
				break ;
			ptr_bottom = ptr_bottom->prev;
		}
		if (ptr_top->cost_a == ptr_bottom->cost_a)
			utils_rotate(stack_a, ptr_top->cost_a, 1, 0);
		else if (utils_abs(ptr_top->cost_a) > utils_abs(ptr_bottom->cost_a))
			utils_rotate(stack_a, ptr_bottom->cost_a, 1, 0);
		else
			utils_rotate(stack_a, ptr_top->cost_a, 1, 0);
		do_push(stack_a, stack_b, 0, 1);
		size--;
		i++;
	}*/
}

void	sort_3(t_stack **stack)
{
	int		pos;
	int		index;
	t_stack	*ptr;
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
				do_rotate_right(stack, 1, 0);
			if (pos == 0 && index == highest)
				do_rotate_left(stack, 1, 0);
			else if (pos == 0 && index > ptr->next->index)
				do_swap(stack, 1, 0);
			ptr = ptr->next;
		}
	}
}
