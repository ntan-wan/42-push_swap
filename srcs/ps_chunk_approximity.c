/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chunk_approximity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:22:48 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/06 18:52:54 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_push_from_stk_a(t_stk **stk_a, t_stk **stk_b, t_stk *target)
{
	rotate_to_top_stk_a(stk_a, target);
	do_push(stk_a, stk_b);
	ft_putstr_fd("pb\n", 1);
}

static t_stk	*find_approximity_from_top(t_stk **stk_a, int approximity)
{
	t_stk	*head_a;

	head_a = *stk_a;
	while (head_a)
	{
		if (head_a->index < approximity)
			return (head_a);
		head_a = head_a->next;
	}
	return (NULL);
}

static t_stk	*find_approximity_from_bottom(t_stk **stk_a, int approximity)
{
	t_stk	*tail_a;

	tail_a = stack_find(*stk_a, NULL);
	while (tail_a)
	{
		if (tail_a->index < approximity)
			return (tail_a);
		tail_a = tail_a->prev;
	}
	return (NULL);
}

void	split_stk_a_into_chunks(t_stk **stk_a, t_stk **stk_b, int chunks)
{
	int		size;
	int		pushed;
	t_stk	*head_a;
	t_stk	*tail_a;
	int		approximity;

	size = stack_size(*stk_a);
	approximity = size / chunks;
	while (stack_size(*stk_a) > (size / chunks))
	{
		pushed = 0;
		while (pushed < (size / chunks))
		{
			init_pos(*stk_a);
			utils_calc_cost(stk_a, 0);
			head_a = find_approximity_from_top(stk_a, approximity);
			tail_a = find_approximity_from_bottom(stk_a, approximity);
			if (utils_abs(head_a->cost_a) < utils_abs(tail_a->cost_a))
				rotate_push_from_stk_a(stk_a, stk_b, head_a);
			else
				rotate_push_from_stk_a(stk_a, stk_b, tail_a);
			pushed++;
		}
		approximity += size / chunks;
	}
}
