/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_act.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:29:11 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/24 16:15:04 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// can refactor
void	act_rotate(t_stack **stack, int cost, int a, int b)
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
			do_rotate_left(stack, a, b);
		else
			do_rotate_right(stack, a ,b);
	}
}

void	act_pop_left_3(t_stack **stack_a, t_stack **stack_b)
{
	/*int	size;
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
		do_push(stack_a, stack_b, 0, 1);*/

	t_stack	*ptr_top;
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
		calc_cost(stack_a, 0);
		while (ptr_top)
		{
			if (ptr_top->index < (size / 2) * i)
				break ;
			ptr_top = ptr_top->next;
		}
		ptr_bottom = stack_get_bottom(*stack_a);
		while (ptr_bottom)
		{
			if (ptr_bottom->index < (size / 2) * i)
				break ;
			ptr_bottom = ptr_bottom->prev;
		}
		if (ptr_top->cost_a == ptr_bottom->cost_a)
			act_rotate(stack_a, ptr_top->cost_a, 1, 0);
		else if (absolutes(ptr_top->cost_a) > absolutes(ptr_bottom->cost_a))
			act_rotate(stack_a, ptr_bottom->cost_a, 1, 0);
		else
			act_rotate(stack_a, ptr_top->cost_a, 1, 0);
		do_push(stack_a, stack_b, 0, 1);
		size--;
		i++;
	}
}
