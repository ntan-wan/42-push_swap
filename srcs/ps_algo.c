/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 09:13:14 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/06 18:57:30 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	get_cheapest_costs(t_stk **stk_a, t_stk **stk_b, int *cost_a, int *cost_b)
{
	t_stk	*ptr_a;
	t_stk	*ptr_b;
	size_t	cheapest;

	cheapest = INT_MAX;
	ptr_b = *stk_b;
	while (ptr_b)
	{
		ptr_a = *stk_a;
		while (ptr_a && ptr_a->pos != ptr_b->target_pos)
			ptr_a = ptr_a->next;
		if (utils_abs(ptr_a->cost_a) + utils_abs(ptr_b->cost_b) < cheapest)
		{
			cheapest = utils_abs(ptr_a->cost_a) + utils_abs(ptr_b->cost_b);
			*cost_a = ptr_a->cost_a;
			*cost_b = ptr_b->cost_b;
		}
		ptr_b = ptr_b->next;
	}	
}

void	cheapeast_action(t_stk **stk_a, t_stk **stk_b)
{
	int		i;
	int		cost_a;
	int		cost_b;
	t_stk	*target_a;
	t_stk	*target_b;

	i = 0;
	get_cheapest_costs(stk_a, stk_b, &cost_a, &cost_b);
	while ((cost_a - i > 0) && (cost_b - i++ > 0))
	{
		rotate_both_left(stk_a, stk_b);
		ft_putstr_fd("rr\n", 1);
	}
	while ((cost_a + i < 0) && (cost_b + i++ < 0))
	{
		rotate_both_right(stk_a, stk_b);
		ft_putstr_fd("rrr\n", 1);
	}
	target_a = find_target_c(stk_a, cost_a, 0);
	target_b = find_target_c(stk_b, cost_b, 1);
	rotate_to_top_stk_a(stk_a, target_a);
	rotate_to_top_stk_b(stk_b, target_b);
	do_push(stk_b, stk_a);
	ft_putstr_fd("pa\n", 1);
}

void	sort_remaining(t_stk **stk_a, t_stk **stk_b)
{
	t_stk	*smallest;
	
	while (*stk_b)
	{
		init_pos(*stk_a);
		init_pos(*stk_b);
		init_target_pos(stk_a, stk_b);
		utils_calc_cost(stk_a, 0);
		utils_calc_cost(stk_b, 1);
		cheapeast_action(stk_a, stk_b);
	}
	init_pos(*stk_a);
	utils_calc_cost(stk_a, 0);
	smallest = find_target_i(stk_a, 0);
	rotate_to_top_stk_a(stk_a, smallest);
}
