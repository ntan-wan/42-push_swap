/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:07:05 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/19 17:54:19 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    sort_2(t_stack **stack)
{
    do_sa(stack);
}

void    sort_3(int ac, t_stack **stack)
{
    int pos;
    int index;
    int next_index;
    int max_index;
    t_stack *head;

    max_index = ac - 2;
    head = *stack;
    while (ac-- > 1)
    {
        head = *stack;
        init_pos(head);
        next_index = head->next->index;
        while (head)
        {
            pos = head->pos;
            index = head->index;
            if (pos == 0 && index == max_index)
                do_ra(stack);
            if (pos == 1 && index == max_index)
                do_rra(stack);
            if (pos == 0 && index > next_index)
                do_sa(stack);
            head = head->next;
        }
    }
}

void    sort()
{

}