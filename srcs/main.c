/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:24:16 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/25 17:58:14 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	util_print(t_stack **stack)
{
	t_stack	*ptr;
	//t_stack	*bottom;

	ptr = *stack;
	//bottom = stack_find(*stack);
	ft_printf("v ");
	while (ptr)
	{
		ft_printf("|%d|", ptr->value);
		ptr = ptr->next;
	}
	ft_printf("\n");
	/*ft_printf("v ");
	while (bottom)
	{
		ft_printf("|%d|", bottom->value);
		bottom = bottom->prev;
	}
	ft_printf("\n");*/
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

static void	get_costs(t_stk **stack_a, t_stk **stack_b, int *cost_a, int *cost_b)
{
	t_stack	*ptr_a;
	t_stack	*ptr_b;
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

static void	cheapeast_action(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	int	cost_a;
	int	cost_b;
	t_stack	*target_a;
	t_stack	*target_b;
	
	i = 0;	
	get_costs(stack_a, stack_b, &cost_a, &cost_b);
	while ((cost_a - i > 0) && (cost_b - i++ > 0))
		rotate_both_left(stack_a, stack_b);
	while ((cost_a + i < 0) && (cost_b + i++ < 0))
		rotate_both_right(stack_a, stack_b);
	target_a = find_target_c(stack_a, cost_a, 0);
	target_b = find_target_c(stack_b, cost_b, 1);
	utils_rotate_to_top(stack_a, target_a, 1, 0);
	utils_rotate_to_top(stack_b, target_b, 0, 1);
	do_push(stack_b, stack_a, 1, 0);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest;

	sort_left_3(stack_a, stack_b);
	sort_3(stack_a);
	while (*stack_b != NULL)
	{
		init_pos(*stack_a);
		init_pos(*stack_b);
		init_target_pos(stack_a, stack_b);
		utils_calc_cost(stack_a, 0);
		utils_calc_cost(stack_b, 1);
		cheapeast_action(stack_a, stack_b);
	}
	smallest = find_target_i(stack_a, 0);
	utils_rotate_to_top(stack_a, smallest, 1, 0);
}

int	main(int ac, char **av)
{
	(void)ac;
	int		size;
	t_stack *stack_a;
	t_stack *stack_b;

	// if (!is_input) ...
	stack_a = stack_fill(av);
	stack_b = NULL;
	size = stack_size(stack_a);
	init_index(stack_a, size);
	push_swap(&stack_a, &stack_b);
	//utils_free_stack(&stack_a);
	utils_free_stack(&stack_b);
	util_print(&stack_a);
	//util_print(&stack_b);
	return (0);
}