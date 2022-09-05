/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:07:05 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/05 18:42:37 by ntan-wan         ###   ########.fr       */
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

void	rotate_push(t_stk **src, t_stk **dest, t_stk *target, char *instruc)
{
	utils_rotate_to_top(src, target, 1);
	do_push(src, dest);
	ft_putstr_fd(instruc, 1);
}

t_stk	*find_approximity_index_from_top(t_stk **stk_a, int approximity)
{
	t_stk	*head_a;

	head_a = *stk_a;
	while (head_a)
	{
		if (head_a->index < approximity)
			return (head_a);
		head_a = head_a->next;
	}
	return (NULL);
}

t_stk	*find_approximity_index_from_bottom(t_stk **stk_a, int approximity)
{
	t_stk	*tail_a;
	
	tail_a = stack_find(*stk_a, NULL);
	while (tail_a)
	{
		if (tail_a->index < approximity)
			return (tail_a);
		tail_a = tail_a->prev;
	}
	return (NULL);
}

void	divide_stk_a_into_chunks(t_stk **stk_a, t_stk **stk_b, int chunks)
{
	int		size;
	int		pushed;
	t_stk	*head_a;
	t_stk	*tail_a;
	int		approximity;

	size = stack_size(*stk_a);
	approximity = size / chunks;
	while (stack_size(*stk_a) > (size / chunks))
	{
		pushed = 0;
		while(pushed < (size / chunks))
		{
			init_pos(*stk_a);
			utils_calc_cost(stk_a, 0);
			head_a = find_approximity_index_from_top(stk_a, approximity);
			tail_a = find_approximity_index_from_bottom(stk_a, approximity);
			if (utils_abs(head_a->cost_a) < utils_abs(tail_a->cost_a))
				rotate_push(stk_a, stk_b, head_a, "pb\n");
			else
				rotate_push(stk_a, stk_b, tail_a, "pb\n");
			pushed++;
		}
		approximity += size / chunks;
	}
}

void	sort_left_3(t_stk **stk_a, t_stk **stk_b)
{
	int	size;
	int	pushed;

	pushed = 0;
	size = stack_size(*stk_a);
	while (size > 3 && pushed < size / 2)
	{
		if ((*stk_a)->index < size / 2)
		{
			do_push(stk_a, stk_b);
			ft_putstr_fd("pb\n", 1);
			pushed++;
			size--;
		}
		else
			do_and_print(stk_a, do_rotate_left, "ra\n");
	}
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
