/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:23:03 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/04 19:37:59 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_and_print(t_stk **stk, void (*f)(t_stk **), char *instruc)
{
	f(stk);
	ft_putstr_fd(instruc, 1);
}

void	do_swap(t_stk **stack)
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
	if (third)
		third->prev = first;
	*stack = second;
}

void	do_rotate_left(t_stk **stack)
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
}

void	do_rotate_right(t_stk **stack)
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
}

void	do_push(t_stk **src, t_stk **dst)
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
}
