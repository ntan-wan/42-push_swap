/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 08:31:17 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/24 17:02:01 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_index(t_stack *stack)
{
	int		value;
	int		size;
	t_stack	*highest;
	t_stack	*ptr;

	// do error checking here
	size = stack_size(stack);
	while (size--)
	{
		value = INT_MIN;
		highest = NULL;
		ptr = stack;
		while(ptr)	
		{
			//if INT_MIN ...
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

void	init_pos(t_stack *stack)
{
	int	pos;

	pos = 0;
	while(stack)
	{
		stack->pos = pos;
		stack = stack->next;
		pos++;
	}
}