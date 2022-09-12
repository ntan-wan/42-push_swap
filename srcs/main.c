/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:24:16 by ntan-wan          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/09 15:42:18 by ntan-wan         ###   ########.fr       */
=======
/*   Updated: 2022/08/24 18:53:55 by ntan-wan         ###   ########.fr       */
>>>>>>> b4a64b9f8cd97342e4db64b352ff768ece992bc1
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

<<<<<<< HEAD
static void	push_swap(t_stk **stk_a, t_stk **stk_b)
{
	int		size;

	size = stack_size(*stk_a);
	if (size <= 5)
		split_stk_a_into_chunks(stk_a, stk_b, 1);
	else if (size > 5 && size <= 100)
		split_stk_a_into_chunks(stk_a, stk_b, 2);
	else
		split_stk_a_into_chunks(stk_a, stk_b, 5);
	sort_push_3_left(stk_a, stk_b);
	sort_3(stk_a);
	sort_rest(stk_a, stk_b);
=======
/*static void	util_print(t_stack **stack)
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
}*/

static void	smallest_on_top(t_stack **stack_a)
{
	int		size;
	t_stack	*smallest;

	smallest = *stack_a;
	size = stack_size(*stack_a);
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
		do_cheapest(stack_a, stack_b);
	smallest_on_top(stack_a);
>>>>>>> b4a64b9f8cd97342e4db64b352ff768ece992bc1
}

int	main(int ac, char **av)
{
<<<<<<< HEAD
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
		utils_free_stack(&stk_a);
		utils_free_stack(&stk_b);
	}
=======
	(void)ac;
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = stack_fill(av);
	stack_b = NULL;
	init_index(stack_a);
	// if (!is_input) ...
	push_swap(&stack_a, &stack_b);
	stack_free(&stack_a);
	stack_free(&stack_b);
	//util_print(&stack_a);
>>>>>>> b4a64b9f8cd97342e4db64b352ff768ece992bc1
	return (0);
}
