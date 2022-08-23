/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:24:16 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/23 16:20:12 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	util_print(t_stack **stack)
{
	t_stack	*ptr;

	ptr = *stack;
	ft_printf("v ");
	while (ptr)
	{
		ft_printf("|%d|", ptr->value);
		ptr = ptr->next;
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

static void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	act_pop_left_3(stack_a, stack_b);
	sort_3(stack_a);
	find_target_pos_b(stack_a, stack_b);
	calc_cost(stack_a, 0);
	calc_cost(stack_b, 1);
	while (*stack_b != NULL)
		do_cheapest(stack_a, stack_b);
	//util_print(stack_a);
	//util_print(stack_b);
}

int	main(int ac, char **av)
{
	(void)ac;
	t_stack *stack_a;
	t_stack *stack_b;
	int		size;
	int		max_index;

	stack_a = stack_fill(av);
	stack_b = NULL;
	size = stack_size(stack_a);
	max_index = size -1;
	init_index(stack_a, size);
	// if (!is_input) ...
	push_swap(&stack_a, &stack_b);
	//stack_free(&stack_a);
	//stack_free(&stack_b);
	util_print(&stack_a);
	util_print(&stack_b);
	return (0);
}