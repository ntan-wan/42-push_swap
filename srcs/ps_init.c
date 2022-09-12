/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 08:31:17 by ntan-wan          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/08/31 15:25:11 by ntan-wan         ###   ########.fr       */
=======
/*   Updated: 2022/08/24 17:02:01 by ntan-wan         ###   ########.fr       */
>>>>>>> b4a64b9f8cd97342e4db64b352ff768ece992bc1
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

<<<<<<< HEAD
void	init_index(t_stk *stack, int size)
{
	int		value;
	t_stk	*highest;
	t_stk	*ptr;

=======
void	init_index(t_stack *stack)
{
	int		value;
	int		size;
	t_stack	*highest;
	t_stack	*ptr;

	// do error checking here
	size = stack_size(stack);
>>>>>>> b4a64b9f8cd97342e4db64b352ff768ece992bc1
	while (size--)
	{
		value = INT_MIN;
		highest = NULL;
		ptr = stack;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}

void	init_pos(t_stk *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->pos = pos;
		stack = stack->next;
		pos++;
	}
}

void	init_target_pos(t_stk **stk_a, t_stk **stk_b)
{
	t_stk	*ptr_a;
	t_stk	*ptr_b;

	ptr_b = *stk_b;
	while (ptr_b)
	{
		ptr_a = find_target_i(stk_a, find_target_index(stk_a, ptr_b));
		ptr_b->target_pos = ptr_a->pos;
		ptr_b = ptr_b->next;
	}
}
