/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:07:05 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/05 17:32:47 by ntan-wan         ###   ########.fr       */
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

void	better_algorithm(t_stk **stk_a, t_stk **stk_b, int chunks)
{
	int		size;
	int		pushed;
	t_stk	*head_a;
	t_stk	*tail_a;
	int		approximity;

	size = stack_size(*stk_a);
	approximity = size / chunks;
	//while (pushed < (size / chunks) * (chunks - 1))
	while (stack_size(*stk_a) > (size / chunks))
	{
		pushed = 0;
		//printf("(%d)", approximity);
		init_pos(*stk_a);
		while(pushed < (size / chunks))
		{
			head_a = *stk_a;
			tail_a = stack_find(*stk_a, NULL);
			utils_calc_cost(stk_a, 0);
			while (head_a)
			{
				//printf("head -> %d|", head_a->index);
				if (head_a->index < approximity)
					break ;
				head_a = head_a->next;
			}
			while (tail_a)
			{
				//printf("tail -> %d|", tail_a->index);
				if (tail_a->index < approximity)
					break ;
				tail_a = tail_a->prev;
			}
			if (utils_abs(head_a->cost_a) < utils_abs(tail_a->cost_a))
			{
				utils_rotate_to_top(stk_a, head_a, 1);
				do_push(stk_a, stk_b);
			}
			else
			{
				utils_rotate_to_top(stk_a, tail_a, 1);
				do_push(stk_a, stk_b);
			}
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
