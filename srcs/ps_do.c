/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:23:03 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/25 18:00:29 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_swap(t_stk **stack, int a, int b)
{
	t_stk	*first;
	t_stk	*second;
	t_stk	*third;

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

void	do_rotate_left(t_stk **stack, int a, int b)
{
	t_stk	*head;
	t_stk	*tail;

	head = *stack;
	tail = stack_find(*stack, NULL);
	*stack = head->next;
	head->next->prev = NULL;
	head->prev = tail;
	head->next = NULL;
	tail->next = head;
	utils_print("ra ", "rb ", a, b);
}

void	do_rotate_right(t_stk **stack, int a, int b)
{
	t_stk	*head;
	t_stk	*second_bottom;
	t_stk	*tail;

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

void	do_push(t_stk **src, t_stk **dst, int a, int b)
{
	t_stk	*head_src;
	t_stk	*head_dst;

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
