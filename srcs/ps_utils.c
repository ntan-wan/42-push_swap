/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:24:31 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/07 01:19:17 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	utils_calc_cost(t_stk **stk, int b)
{
	int		size;
	t_stk	*ptr;

	ptr = *stk;
	size = stack_size(*stk);
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

size_t	utils_abs(int num)
{
	if (num < 0)
		num = -num;
	return (num);
}

void	utils_free_stack(t_stk **stack)
{
	t_stk	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	rotate_to_top_stk_a(t_stk **stk_a, t_stk *target)
{
	while (*stk_a != target)
	{
		if (target->cost_a < 0)
		{
			do_rotate_right(stk_a);
			ft_putstr_fd("rra\n", 1);
		}
		else if (target->cost_a > 0)
		{
			do_rotate_left(stk_a);
			ft_putstr_fd("ra\n", 1);
		}
	}
}

void	rotate_to_top_stk_b(t_stk **stk_b, t_stk *target)
{
	while (*stk_b != target)
	{
		if (target->cost_b < 0)
		{
			do_rotate_right(stk_b);
			ft_putstr_fd("rrb\n", 1);
		}
		else if (target->cost_b > 0)
		{
			do_rotate_left(stk_b);
			ft_putstr_fd("rb\n", 1);
		}
	}
}
