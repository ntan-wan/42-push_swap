/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:24:16 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/05 18:58:18 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	util_print(t_stk **stack)
{
	t_stk	*ptr;
	t_stk	*bottom;

	ptr = *stack;
	bottom = stack_find(*stack, NULL);
	ft_printf("T to B ");
	while (ptr)
	{
		ft_printf("|%d|", ptr->value);
		ptr = ptr->next;
	}
	ft_printf("\n");
	ft_printf("B to T ");
	while (bottom)
	{
		ft_printf("|%d|", bottom->value);
		bottom = bottom->prev;
	}
	ft_printf("\n");
	ptr = *stack;
	ft_printf("i ");
	while (ptr)
	{
		ft_printf("|%d|", ptr->index);
		ptr = ptr->next;
	}
	ft_printf("\n");
	ptr = *stack;
	ft_printf("p ");
	while (ptr)
	{
		ft_printf("|%d|", ptr->pos);
		ptr = ptr->next;
	}
	ft_printf("\n");
	ptr = *stack;
	ft_printf("t ");
	while (ptr)
	{
		ft_printf("|%d|", ptr->target_pos);
		ptr = ptr->next;
	}
	ft_printf("\n");
	ptr = *stack;
	ft_printf("a ");
	while (ptr)
	{
		ft_printf("|%d|", ptr->cost_a);
		ptr = ptr->next;
	}
	ft_printf("\n");
	ptr = *stack;
	ft_printf("b ");
	while (ptr)
	{
		ft_printf("|%d|", ptr->cost_b);
		ptr = ptr->next;
	}
	ft_printf("\n");
}

static void	get_costs(t_stk **stk_a, t_stk **stk_b, int *cost_a, int *cost_b)
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

static void	cheapeast_action(t_stk **stk_a, t_stk **stk_b)
{
	int		i;
	int		cost_a;
	int		cost_b;
	t_stk	*target_a;
	t_stk	*target_b;

	i = 0;
	get_costs(stk_a, stk_b, &cost_a, &cost_b);
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
	utils_rotate_to_top(stk_a, target_a, 1);
	utils_rotate_to_top(stk_b, target_b, 0);
	do_push(stk_b, stk_a);
	ft_putstr_fd("pa\n", 1);
}

static void	push_swap(t_stk **stk_a, t_stk **stk_b)
{
	t_stk	*smallest;

	//sort_left_3(stk_a, stk_b);
	//sort_3(stk_a);
	divide_stk_a_into_chunks(stk_a, stk_b, 4);
	while (*stk_b)
	{
		init_pos(*stk_a);
		init_pos(*stk_b);
		init_target_pos(stk_a, stk_b);
		utils_calc_cost(stk_a, 0);
		utils_calc_cost(stk_b, 1);
		cheapeast_action(stk_a, stk_b);
	}
	smallest = find_target_i(stk_a, 0);
	utils_rotate_to_top(stk_a, smallest, 1);
}

int	main(int ac, char **av)
{
	int		size;
	t_stk	*stk_a;
	t_stk	*stk_b;

	if (ac > MIN_ARGS)
	{
		if (!is_input(av))
			error_exit("Error\n");
		stk_a = stack_fill(av);
		stk_b = NULL;
		size = stack_size(stk_a);
		init_index(stk_a, size);
		if (!is_sorted(stk_a))
			push_swap(&stk_a, &stk_b);
		util_print(&stk_a);
		utils_free_stack(&stk_a);
		utils_free_stack(&stk_b);
	}
	return (0);
}
