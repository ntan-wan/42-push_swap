/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:24:16 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/07 01:21:34 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*static void	util_print(t_stk **stack)
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
}*/

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
		utils_free_stack(&stk_a);
		utils_free_stack(&stk_b);
	}
	return (0);
}
