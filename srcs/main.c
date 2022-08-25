/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:24:16 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/25 08:18:22 by ntan-wan         ###   ########.fr       */
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

static void	smallest_rotate_top(t_stack **stack_a)
{
	int	size;

	size = stack_size(*stack_a);
	t_stack	*smallest;

	smallest = *stack_a;
	while (smallest)
	{
		if (smallest->index == 0)
			break ;
		smallest = smallest->next;
	}
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
	find_target_pos(stack_a, stack_b);
	utils_calc_cost(stack_a, 0);
	utils_calc_cost(stack_b, 1);
	while (*stack_b != NULL)
		do_cheapest_action(stack_a, stack_b);
	smallest_rotate_top(stack_a);
}

int	main(int ac, char **av)
{
	(void)ac;
	int		size;
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = stack_fill(av);
	stack_b = NULL;
	size = stack_size(stack_a);
	init_index(stack_a, size);
	// if (!is_input) ...
	push_swap(&stack_a, &stack_b);
	//utils_free_stack(&stack_a);
	utils_free_stack(&stack_b);
	util_print(&stack_a);
	//util_print(&stack_b);
	return (0);
}