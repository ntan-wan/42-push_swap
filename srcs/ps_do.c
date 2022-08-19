/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:23:03 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/19 15:49:53 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    do_sa(t_stack **stack)
{
    t_stack *head;
    t_stack *second;

    head = *stack;
    second = head->next;
    head->next = second->next;
    second->next = head;
    *stack = second;
    ft_printf("sa\n");
}

void    do_ra(t_stack **stack)
{
    t_stack *head;
    t_stack *tail;

    head = *stack;
    *stack = head->next;
    head->next = NULL;
    tail = stack_get_top(*stack);
    tail->next = head;
    ft_printf("ra\n");
}

void    do_rra(t_stack **stack)
{
    t_stack *head;
    t_stack *tail;

    head = *stack;
    tail = stack_get_top(head);
    tail->next = head;
    *stack = tail;
    while (head->next != tail)
        head = head->next;
    head->next = NULL;
    ft_printf("rra\n");
}