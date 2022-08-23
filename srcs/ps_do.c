/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:23:03 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/23 16:09:52 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    do_sa(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	ft_printf("sa\n");
}

void    do_ra(t_stack **stack)
{
	t_stack *head;
	t_stack *tail;

	head = *stack;
	tail = stack_get_top(*stack);
	*stack = head->next;
	tail->next = head;
	head->next = NULL;
	ft_printf("ra\n");
}

void    do_rra(t_stack **stack)
{
	t_stack *head;
	t_stack *ptr;
	t_stack *tail;

	head = *stack;
	ptr = head;
	tail = stack_get_top(*stack);
	*stack = tail;
	tail->next = head;
	while (ptr->next != tail)
		ptr = ptr->next;
	ptr->next = NULL;
	ft_printf("rra\n");
}

void    do_push(t_stack **src, t_stack **dst)
{
	t_stack *head;

	head = *src;
	*src = head->next;
	head->next = *dst;
	*dst = head;
	ft_printf("pb\n");
}
void	do_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *ptr_a;
	t_stack *ptr_b;
	size_t	cheapest;
	int		cost_a;
	int		cost_b;

	cheapest = INT_MAX;
	ptr_b = *stack_b;
	while (ptr_b)
	{
	    ptr_a = *stack_a;
		while (ptr_a)
		{
            if (ptr_a->pos == ptr_b->target_pos)
                break ;
			ptr_a = ptr_a->next;
		}
        if (absolutes(ptr_a->cost_a + ptr_b->cost_b) < cheapest)
		{
            cheapest = absolutes(ptr_a->cost_a + ptr_b->cost_b);
			cost_a = ptr_a->cost_a;
			cost_b = ptr_b->cost_b;
		}
		ptr_b = ptr_b->next;
	}
	//ft_printf("%d\n", cost_a);
	//ft_printf("%d\n", cost_b);
	act_rotate(stack_a, cost_a, 0);
	act_rotate(stack_b, cost_b, 1);
	do_push(stack_b, stack_a);
	init_pos(*stack_a);
	init_pos(*stack_b);
	calc_cost(stack_a, 0);
	calc_cost(stack_b, 1);
	find_target_pos_b(stack_a, stack_b);
}
