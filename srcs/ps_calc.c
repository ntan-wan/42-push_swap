/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:48:32 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/21 15:01:29 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	calc_cost(t_stack **stk, int b)
{
	int	size;
	t_stack *ptr;

	ptr = *stk;
	size = stack_size(*stk);
	init_pos(*stk);
	while (ptr)
	{
		if (ptr->pos <= size / 2)
		{
			if (b)
				ptr->cost_b = ptr->pos;
			else
				ptr->cost_a = ptr->pos;
		}
		else
		{
			if (b)
				ptr->cost_b = ptr->pos - size;
			else
				ptr->cost_a = ptr->pos - size;
		}
		ptr = ptr->next;
	}
}