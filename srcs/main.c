/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:24:16 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/24 15:56:18 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	util_print(t_stack **stack)
{
	t_stack	*ptr;
	//t_stack	*bottom;

	ptr = *stack;
	//bottom = stack_get_bottom(*stack);
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

void	print_instruct(char *instruct_a, char *instruct_b, int a, int b)
{
	if (a)
		ft_printf(instruct_a);
	else if (b)
		ft_printf(instruct_b);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	act_pop_left_3(stack_a, stack_b);
	//sort_3(stack_a);
	/*find_target_pos_b(stack_a, stack_b);
	calc_cost(stack_a, 0);
	calc_cost(stack_b, 1);*/
	//int i;

	//i = 0;
	//while (i < 7)
	/*while (*stack_b != NULL)
	{
		do_cheapest(stack_a, stack_b);
		//i++;
	}
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
	}*/

	//util_print(stack_a);
	//util_print(stack_b);
}

int	main(int ac, char **av)
{
	(void)ac;
	t_stack *stack_a;
	t_stack *stack_b;
	int		size;

	stack_a = stack_fill(av);
	stack_b = NULL;
	size = stack_size(stack_a);
	init_index(stack_a, size);
	// if (!is_input) ...
	push_swap(&stack_a, &stack_b);
	//stack_free(&stack_a);
	//stack_free(&stack_b);
	util_print(&stack_a);
	util_print(&stack_b);
	return (0);
}