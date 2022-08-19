/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:23:03 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/20 07:06:52 by ntan-wan         ###   ########.fr       */
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
