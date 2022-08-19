/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:24:16 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/19 16:01:18 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	util_print(t_stack *stack)
{
	while (stack)
	{
		ft_printf("|%d|", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_stack *stack_a;
	//t_stack *stack_b;
	(void)ac;	
	stack_a = stack_fill(av);
	//stack_b = NULL;
	init_index(ac, stack_a);
	//sort_2(&stack_a);
	init_pos(stack_a);
	//do_ra(&stack_a);
	//do_rra(&stack_a);
	//do_sa(&stack_a);
	//sort_2(&stack_a);
	sort_3(ac, &stack_a);
	util_print(stack_a);
	stack_free(&stack_a);
	util_print(stack_a);
	return (0);
}