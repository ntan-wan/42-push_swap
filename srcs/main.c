/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:24:16 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/25 11:44:28 by ntan-wan         ###   ########.fr       */
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

static void	cheapeast_action(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*ptr_a;
	t_stack	*ptr_b;
	size_t	cheapest;
	int		cost_a;
	int		cost_b;

	cheapest = INT_MAX;
	ptr_b = *stack_b;
	while (ptr_b)
	{
		ptr_a = *stack_a;
		while (ptr_a && ptr_a->pos != ptr_b->target_pos)
			ptr_a = ptr_a->next;
		if (utils_abs(ptr_a->cost_a) + utils_abs(ptr_b->cost_b) < cheapest)
		{
			cheapest = utils_abs(ptr_a->cost_a) + utils_abs(ptr_b->cost_b);
			cost_a = ptr_a->cost_a;
			cost_b = ptr_b->cost_b;
		}
		ptr_b = ptr_b->next;
	}
	int i = 0;
	while (cost_a - i > 0 && cost_b - i > 0)
	{
		do_rotate_both(stack_a, stack_b, cost_a, cost_b);
		i++;
	}
	while (cost_a + i < 0 && cost_b + i < 0)
	{
		do_rotate_both(stack_a, stack_b, cost_a, cost_b);
		i++;
	}
	utils_rotate(stack_a, cost_a, 1, 0);
	utils_rotate(stack_b, cost_b, 0, 1);
	do_push(stack_b, stack_a, 1, 0);
}

static void	smallest_rotate_top(t_stack **stack_a)
{
	int	size;
	t_stack	*smallest;

	size = stack_size(*stack_a);
	smallest = *stack_a;
	while (smallest && smallest->index != 0)
		smallest = smallest->next;
	while (*stack_a != smallest)
	{
		if (smallest->pos <= size / 2)
			do_rotate_left(stack_a, 1, 0);
		else
			do_rotate_right(stack_a, 1, 0);
	}	
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	sort_left_3(stack_a, stack_b);
	sort_3(stack_a);
	while (*stack_b != NULL)
	{
		init_pos(*stack_a);
		init_pos(*stack_b);
		find_target_pos(stack_a, stack_b);
		utils_calc_cost(stack_a, 0);
		utils_calc_cost(stack_b, 1);
		cheapeast_action(stack_a, stack_b);
	}
	smallest_rotate_top(stack_a);
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