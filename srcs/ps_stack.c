/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:15:43 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/25 07:56:42 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

t_stack	*stack_find(t_stack *stack, t_stack *find)
{
	t_stack	*ptr;

	ptr = stack;
	while (ptr && ptr->next != find)
		ptr = ptr->next;
	return (ptr);
}

static void	stack_add_bottom(t_stack *new, t_stack **stack)
{
	t_stack	*bottom;

	bottom = stack_find(*stack, NULL);
	bottom->next = new;
	new->prev = bottom;
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_stack	*stack_fill(char **av)
{
	int		i;
	int		num;
	t_stack	*stack;

	i = 1;
	num = 0;
	while (av[i])
	{
		// do error checking here
		num = ft_atoi(av[i]);
		//if (num > INT_MAX || NUM < INT_MIN)
		if (i == 1)
			stack = stack_new(num);
		else
			stack_add_bottom(stack_new(num), &stack);
		i++;
	}
	return (stack);
}
