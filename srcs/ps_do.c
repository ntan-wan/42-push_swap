/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:23:03 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/25 11:26:44 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_swap(t_stack **stack, int a, int b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	first->prev = second;
	first->next = third;
	second->prev = NULL;
	second->next = first;
	third->prev = first;
	*stack = second;
	utils_print("sa ", "sb ", a, b);
}

void	do_rotate_left(t_stack **stack, int a, int b)
{
	t_stack	*head;
	t_stack	*tail;

	head = *stack;
	tail = stack_find(*stack, NULL);
	*stack = head->next;
	head->next->prev = NULL;
	head->prev = tail;
	head->next = NULL;
	tail->next = head;
	utils_print("ra ", "rb ", a, b);
}

void	do_rotate_right(t_stack **stack, int a, int b)
{
	t_stack	*head;
	t_stack	*second_bottom;
	t_stack	*tail;

	head = *stack;
	tail = stack_find(*stack, NULL);
	*stack = tail;
	head->prev = tail;
	second_bottom = stack_find(head, tail);
	second_bottom->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	utils_print("rra ", "rrb ", a, b);
}

void	do_push(t_stack **src, t_stack **dst, int a, int b)
{
	t_stack	*head_src;
	t_stack	*head_dst;

	head_src = *src;
	head_dst = *dst;
	*src = head_src->next;
	if (head_src->next)
		head_src->next->prev = NULL;
	head_src->prev = NULL;
	head_src->next = *dst;
	*dst = head_src;
	if (head_dst)
		head_dst->prev = head_src;
	utils_print("pa ", "pb ", a, b);
}

void	do_rotate_both( t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
	{
		do_rotate_left(stack_a, 0, 0);
		do_rotate_left(stack_b, 0, 0);
		ft_printf("rr ");	
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		do_rotate_right(stack_a, 0, 0);
		do_rotate_right(stack_b, 0, 0);
		ft_printf("rrr ");
	}
}
