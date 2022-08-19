/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 08:31:17 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/19 09:41:22 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_index(t_stack *stack)
{
	int	value;
	
	value = INT_MIN;
	// do error checking here
	while(stack)	
	{
		if (stack->value > value && stack->index == 0)
		{
			value = stack->value;
		}
		else
			stack = stack->next;
	}
}