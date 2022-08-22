/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:23:03 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/22 13:51:01 by ntan-wan         ###   ########.fr       */
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


void    do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	//compare cost first
	//total cost =  target_pos->cost_a + stack_b->cost_b
	int 	total_cost;
	t_stack *ptr_b;

	total_cost = 0;
	ptr_a = *stack_a;
	ptr_b = *stack_b;
	while (ptr_b)
	{
		while (ptr_a)
		{
			ptr_a
		}
		if (ptr_b->cost_b + )
		ptr_b = ptr_b->next;
	}

}