/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:15:43 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/01 13:18:30 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stk	*stack_new(int value)
{
	t_stk	*new;

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

t_stk	*stack_find(t_stk *stack, t_stk *stopper)
{
	t_stk	*ptr;

	ptr = stack;
	while (ptr && ptr->next != stopper)
		ptr = ptr->next;
	return (ptr);
}

static void	stk_add_bottom(t_stk *new, t_stk **stack)
{
	t_stk	*bottom;

	bottom = stack_find(*stack, NULL);
	bottom->next = new;
	new->prev = bottom;
}

int	stack_size(t_stk *stack)
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

t_stk	*stack_fill(char **av)
{
	int		i;
	int		num;
	t_stk	*stack;
	char	**inputs;

	i = -1;
	num = 0;
	inputs = get_all_inputs(av, get_input_size(av));
	while (inputs[++i])
	{
		num = ft_atoi(inputs[i]);
		if (i == 0)
			stack = stack_new(num);
		else
			stk_add_bottom(stack_new(num), &stack);
	}
	free_input_arr(&inputs);
	return (stack);
}
