/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:39:54 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/05 13:11:05 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	print_instructions(t_list *instructions)
{
	while (instructions)
	{
		ft_printf("%s", (char *)instructions->content);
		instructions = instructions->next;
	}	
}

void	print_stack(t_stk *stk)
{
	while (stk)
	{
		ft_printf("%d|", stk->value);
		stk = stk->next;
	}	
	ft_printf("\n");
}

void	print_result(t_stk **stk_a, t_stk **stk_b)
{
	init_index(*stk_a, stack_size(*stk_a));
	if (is_sorted(*stk_a) && !*stk_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
