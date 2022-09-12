/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:23:03 by ntan-wan          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/05 12:19:05 by ntan-wan         ###   ########.fr       */
=======
/*   Updated: 2022/08/24 18:54:56 by ntan-wan         ###   ########.fr       */
>>>>>>> b4a64b9f8cd97342e4db64b352ff768ece992bc1
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
<<<<<<< HEAD
	third = NULL;
	first->prev = second;
	if (second)
	{
		third = second->next;
		second->prev = NULL;
		second->next = first;
		*stack = second;
	}
	first->next = third;
	if (third)
		third->prev = first;
=======
	first->next = second->next;
	second->next = first;
	*stack = second;
	utils_print("sa ", "sb ", a, b);
>>>>>>> b4a64b9f8cd97342e4db64b352ff768ece992bc1
}

void	do_rotate_left(t_stk **stack)
{
	t_stk	*head;
	t_stk	*tail;

	head = *stack;
<<<<<<< HEAD
	tail = stack_find(*stack, NULL);
	if (head != tail)
	{
		*stack = head->next;
		head->next->prev = NULL;
		head->prev = tail;
		head->next = NULL;
		tail->next = head;
	}
=======
	tail = stack_get_bottom(*stack);
	*stack = head->next;
	tail->next = head;
	head->next = NULL;
	utils_print("ra ", "rb ", a, b);
>>>>>>> b4a64b9f8cd97342e4db64b352ff768ece992bc1
}

void	do_rotate_right(t_stk **stack)
{
	t_stk	*head;
	t_stk	*second_bottom;
	t_stk	*tail;

	head = *stack;
<<<<<<< HEAD
	tail = stack_find(*stack, NULL);
	if (head != tail)
	{
		*stack = tail;
		head->prev = tail;
		second_bottom = stack_find(head, tail);
		second_bottom->next = NULL;
		tail->prev = NULL;
		tail->next = head;
	}
=======
	ptr = head;
	tail = stack_get_bottom(*stack);
	*stack = tail;
	tail->next = head;
	while (ptr->next != tail)
		ptr = ptr->next;
	ptr->next = NULL;
	utils_print("rra ", "rrb ", a, b);
>>>>>>> b4a64b9f8cd97342e4db64b352ff768ece992bc1
}

void	do_push(t_stk **src, t_stk **dst)
{
	t_stk	*head_src;
	t_stk	*head_dst;

<<<<<<< HEAD
	if (!*src)
		return ;
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
=======
	head = *src;
	*src = head->next;
	head->next = *dst;
	*dst = head;
	utils_print("pa ", "pb ", a, b);
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
        if (utils_absolutes(ptr_a->cost_a) + utils_absolutes(ptr_b->cost_b) < cheapest)
		{
            cheapest = utils_absolutes(ptr_a->cost_a) + utils_absolutes(ptr_b->cost_b);
			cost_a = ptr_a->cost_a;
			cost_b = ptr_b->cost_b;
		}
		ptr_b = ptr_b->next;
	}
	int i = 0;
	while (cost_a - i > 0 && cost_b - i > 0)
	{
		do_rotate_left(stack_a, 0, 0);
		do_rotate_left(stack_b, 0, 0);
		ft_printf("rr ");
		i++;
	}
	while (cost_a + i < 0 && cost_b + i < 0)
	{
		do_rotate_right(stack_a, 0, 0);
		do_rotate_right(stack_b, 0, 0);
		ft_printf("rrr ");
		i++;
	}
	utils_rotate(stack_a, cost_a, 1, 0);
	utils_rotate(stack_b, cost_b, 0, 1);
	do_push(stack_b, stack_a, 1, 0);
	init_pos(*stack_a);
	init_pos(*stack_b);
	utils_calc_cost(stack_a, 0);
	utils_calc_cost(stack_b, 1);
	find_target_pos(stack_a, stack_b);
>>>>>>> b4a64b9f8cd97342e4db64b352ff768ece992bc1
}
