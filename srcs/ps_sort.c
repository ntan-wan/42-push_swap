/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:07:05 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/20 07:24:23 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sort(t_stack *stack)
{
	while (stack && stack->next != NULL)
	{
		if (stack->index - stack->next->index > 0)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_3(int ac, t_stack **stack)
{
	int		pos;
	int		index;
	int		max_index;
	t_stack	*ptr;

	max_index = ac - 2;
	while (!is_sort(*stack))
	{
		ptr = *stack;
		init_pos(ptr);
		while (ptr)
		{
			pos = ptr->pos;
			index = ptr->index;
			if (pos == 1 && index == max_index)
				do_rra(stack);
			if (pos == 0 && index == max_index)
				do_ra(stack);
			else if (pos == 0 && index > ptr->next->index)
				do_sa(stack);
			ptr = ptr->next;
		}
	}
}

/*void    sort()
{

}*/
