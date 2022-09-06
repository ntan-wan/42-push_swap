/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 09:13:14 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/06 11:09:29 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_push(t_stk **src, t_stk **dest, t_stk *target, char *instruc)
{
	utils_rotate_to_top(src, target, 1);
	do_push(src, dest);
	ft_putstr_fd(instruc, 1);
}

t_stk	*find_approximity_from_top(t_stk **stk_a, int approximity)
{
	t_stk	*head_a;

	head_a = *stk_a;
	while (head_a)
	{
		if (head_a->index < approximity)
		{
			//printf(" head(%d)", head_a->cost_a);
			return (head_a);
		}
		head_a = head_a->next;
	}
	return (NULL);
}

t_stk	*find_approximity_from_bottom(t_stk **stk_a, int approximity)
{
	t_stk	*tail_a;

	tail_a = stack_find(*stk_a, NULL);
	while (tail_a)
	{
		if (tail_a->index < approximity)
		{
			//printf("tail(%d)", tail_a->cost_a);
			return (tail_a);
		}
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
		while (pushed < (size / chunks))
		{
			init_pos(*stk_a);
			utils_calc_cost(stk_a, 0);
			head_a = find_approximity_from_top(stk_a, approximity);
			tail_a = find_approximity_from_bottom(stk_a, approximity);
			if (utils_abs(head_a->cost_a) < utils_abs(tail_a->cost_a))
				rotate_push(stk_a, stk_b, head_a, "pb\n");
			else
				rotate_push(stk_a, stk_b, tail_a, "pb\n");
			pushed++;
		}
		approximity += size / chunks;
	}
}

void	rotate_to_top_stk_a(t_stk **stk_a , t_stk *target)
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

void	rotate_to_top_stk_b(t_stk **stk_b , t_stk *target)
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

void	push_all_left_3(t_stk **stk_a, t_stk **stk_b)
{
	int	size;

	size = stack_size(*stk_a);
	while (size-- > 3)
	{
		do_push(stk_a, stk_b);
		ft_putstr_fd("pb\n", 1);
	}
}

void	better_algo(t_stk **stk_a, t_stk **stk_b)
{
	t_stk	*target_stk_a;
	t_stk	*target_stk_b;

	divide_stk_a_into_chunks(stk_a, stk_b, 4);
	push_all_left_3(stk_a, stk_b);
	sort_3(stk_a);
	while (*stk_b)
	{
		init_pos(*stk_a);
		init_pos(*stk_b);
		utils_calc_cost(stk_a, 0);
		utils_calc_cost(stk_b, 1);
		target_stk_a = find_target_i(stk_a, find_lowest_index(*stk_a));
		target_stk_b = find_target_i(stk_b, find_highest_index(*stk_b));
		rotate_to_top_stk_a(stk_a, target_stk_a);
		rotate_to_top_stk_b(stk_b, target_stk_b);
		do_push(stk_b, stk_a);
		ft_putstr_fd("pa\n", 1);
	}
}