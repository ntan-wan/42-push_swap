/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:24:31 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/25 07:54:24 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	utils_rotate(t_stack **stack, int cost, int a, int b)
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

void	utils_calc_cost(t_stack **stk, int b)
{
	int	size;
	t_stack *ptr;

	ptr = *stk;
	size = stack_size(*stk);
	init_pos(*stk);
	while (ptr)
	{
		if (ptr->pos <= size / 2)
		{
			if (b)
				ptr->cost_b = ptr->pos;
			else
				ptr->cost_a = ptr->pos;
		}
		else
		{
			if (b)
				ptr->cost_b = ptr->pos - size;
			else
				ptr->cost_a = ptr->pos - size;
		}
		ptr = ptr->next;
	}
}

void	utils_print(char *instruct_a, char *instruct_b, int a, int b)
{
	if (a)
		ft_printf(instruct_a);
	else if (b)
		ft_printf(instruct_b);
}

size_t utils_absolutes(int num)
{
	if (num < 0)
		num = -num;
	return (num);
}

void	utils_free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}