/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:23:03 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/24 10:19:59 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    do_swap(t_stack **stack, int a, int b)
{
	t_stack *first;
	t_stack *second;

	first = *stack;
	second = first->next;
	first->prev = first->next;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	*stack = second;
	//ft_printf("sa\n");
	print_instruct("sa ", "sb ", a, b);
}

void    do_rotate_left(t_stack **stack, int a, int b)
{
	t_stack *head;
	t_stack *tail;

	head = *stack;
	tail = stack_get_bottom(*stack);
	*stack = head->next;
	head->prev = tail;
	head->next = NULL;
	tail->prev = stack_second_bottom(head, tail);
	tail->next = head;
	//ft_printf("ra\n");
	print_instruct("ra ", "rb ", a, b);
}

void    do_rotate_right(t_stack **stack, int a, int b)
{
	t_stack *head;
	t_stack *second_bottom;
	t_stack *tail;

	head = *stack;
	tail = stack_get_bottom(*stack);
	*stack = tail;
	head->prev = tail;
	tail->prev = NULL;
	tail->next = head;
	second_bottom = stack_second_bottom(head, tail);
	second_bottom->next = NULL;
	//ft_printf("rra\n");
	print_instruct("rra ", "rrb ", a, b);
}

void    do_push(t_stack **src, t_stack **dst, int a, int b)
{
	t_stack *head_a;
	//t_stack	*head_b;

	head_a = *src;
	//head_b = *dst;
	*src = head_a->next;
	//head_a->next->prev = NULL;
	head_a->prev = NULL;
	head_a->next = *dst;
	*dst = head_a;
	//head_b->prev = head_a;
	//ft_printf("pb\n");
	print_instruct("pa ", "pb ", a, b);
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
        if (absolutes(ptr_a->cost_a) + absolutes(ptr_b->cost_b) < cheapest)
		{
            cheapest = absolutes(ptr_a->cost_a) + absolutes(ptr_b->cost_b);
			cost_a = ptr_a->cost_a;
			cost_b = ptr_b->cost_b;
		}
		ptr_b = ptr_b->next;
	}
	//ft_printf("%d\n", cost_a);
	//ft_printf("%d\n", cost_b);
	int i = 0;
	while (cost_a - i > 0 && cost_b - i > 0)
	{
		//if (cost_a > 0 && cost_b > 0)
		//{
		do_rotate_left(stack_a, 0, 0);
		do_rotate_left(stack_b, 0, 0);
		ft_printf("rr ");
		i++;
		//}
	}
	while (cost_a + i < 0 && cost_b + i < 0)
	{
		do_rotate_right(stack_a, 0, 0);
		do_rotate_right(stack_b, 0, 0);
		ft_printf("rrr ");
		i++;
	}
	//init_pos(*stack_a);
	//init_pos(*stack_b);
	//find_target_pos_b(stack_a, stack_b);
	act_rotate(stack_a, cost_a, 1,0);
	act_rotate(stack_b, cost_b, 0, 1);
	do_push(stack_b, stack_a, 1, 0);
	init_pos(*stack_a);
	init_pos(*stack_b);
	calc_cost(stack_a, 0);
	calc_cost(stack_b, 1);
	find_target_pos_b(stack_a, stack_b);
}
