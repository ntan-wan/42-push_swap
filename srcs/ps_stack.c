/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:15:43 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/24 09:37:23 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof *new);
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

t_stack	*stack_second_bottom(t_stack *head, t_stack *tail)
{
	while (head && head->next != tail)
		head = head->next;
	return (head);	
}

t_stack *stack_get_bottom(t_stack *stack)
{	
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_add_bottom(t_stack *new, t_stack **stack)
{
	t_stack *bottom;

	bottom = stack_get_bottom(*stack);
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
	int	i;
	int	num;
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

void	stack_free(t_stack **stack)
{
	t_stack *temp;
	
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
