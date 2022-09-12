/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
=======
<<<<<<< HEAD:srcs/ps_rotate_both.c
/*   ps_rotate_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:26:41 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/05 12:22:51 by ntan-wan         ###   ########.fr       */
=======
>>>>>>> b4a64b9f8cd97342e4db64b352ff768ece992bc1
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2022/08/24 22:24:31 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/07 01:19:17 by ntan-wan         ###   ########.fr       */
=======
/*   Created: 2022/08/24 18:00:52 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/24 18:52:12 by ntan-wan         ###   ########.fr       */
>>>>>>> b4a64b9f8cd97342e4db64b352ff768ece992bc1:srcs/ps_utils.c
>>>>>>> b4a64b9f8cd97342e4db64b352ff768ece992bc1
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

<<<<<<< HEAD
void	utils_calc_cost(t_stk **stk, int b)
{
	int		size;
	t_stk	*ptr;

	ptr = *stk;
	size = stack_size(*stk);
	while (ptr)
	{
		if (ptr->pos <= size / 2)
		{
			if (b)
				ptr->cost_b = ptr->pos;
			else
				ptr->cost_a = ptr->pos;
		}
		else
		{
			if (b)
				ptr->cost_b = ptr->pos - size;
			else
				ptr->cost_a = ptr->pos - size;
		}
		ptr = ptr->next;
	}
}

size_t	utils_abs(int num)
=======
<<<<<<< HEAD:srcs/ps_rotate_both.c
void	rotate_both_left(t_stk **stk_a, t_stk **stk_b)
=======
void	utils_print(char *instruct_a, char *instruct_b, int a, int b)
{
	if (a)
		ft_printf(instruct_a);
	else if (b)
		ft_printf(instruct_b);
}

size_t utils_absolutes(int num)
>>>>>>> b4a64b9f8cd97342e4db64b352ff768ece992bc1
{
	if (num < 0)
		num = -num;
	return (num);
}

<<<<<<< HEAD
void	utils_free_stack(t_stk **stack)
{
	t_stk	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	rotate_to_top_stk_a(t_stk **stk_a, t_stk *target)
{
	while (*stk_a != target)
	{
		if (target->cost_a < 0)
		{
			do_rotate_right(stk_a);
			ft_putstr_fd("rra\n", 1);
		}
		else if (target->cost_a > 0)
		{
			do_rotate_left(stk_a);
			ft_putstr_fd("ra\n", 1);
		}
	}
}

void	rotate_to_top_stk_b(t_stk **stk_b, t_stk *target)
{
	while (*stk_b != target)
	{
		if (target->cost_b < 0)
		{
			do_rotate_right(stk_b);
			ft_putstr_fd("rrb\n", 1);
		}
		else if (target->cost_b > 0)
		{
			do_rotate_left(stk_b);
			ft_putstr_fd("rb\n", 1);
		}
	}
=======
void	utils_rotate(t_stack **stack, int cost,int a, int b)
{
	t_stack	*target;

	target = *stack;
	while (target)
	{
		if (b)
		{
			if (target->cost_b == cost)
				break;
		}
		else if (target->cost_a == cost)
			break ;
		target = target->next;
	}
	while (*stack != target)
	{
		if (cost > 0)
			do_rotate_left(stack,a, b);
		else
			do_rotate_right(stack,a, b);
	}
}

void	utils_calc_cost(t_stack **stk, int b)
>>>>>>> b4a64b9f8cd97342e4db64b352ff768ece992bc1:srcs/ps_utils.c
{
	if (*stk_a)
		do_rotate_left(stk_a);
	if (*stk_b)
		do_rotate_left(stk_b);
}

void	rotate_both_right(t_stk **stk_a, t_stk **stk_b)
{
	if (*stk_a)
		do_rotate_right(stk_a);
	if (*stk_b)
		do_rotate_right(stk_b);
}

void	swap_both(t_stk **stk_a, t_stk **stk_b)
{
	if (*stk_a)
		do_swap(stk_a);
	if (*stk_b)
		do_swap(stk_b);
>>>>>>> b4a64b9f8cd97342e4db64b352ff768ece992bc1
}
