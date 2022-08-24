/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:24:31 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/24 22:34:46 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* stack */
void	stack_free(t_stack **stack);
int		stack_size(t_stack *stack);
t_stack	*stack_fill(char **av);
t_stack	*stack_get_bottom(t_stack *stack);
t_stack	*stack_second_bottom(t_stack *head, t_stack *tail);

/* init */
void	init_index(t_stack *stack);
void	init_pos(t_stack *stack);

/* do */
void	do_swap(t_stack **stack, int a, int b);
void	do_rotate_left(t_stack **stack, int a, int b);
void	do_rotate_right(t_stack **stack, int a, int b);
void	do_push(t_stack **src, t_stack **dst, int a, int b);
void	do_cheapest(t_stack **stack_a, t_stack **stack_b);

/* sort */
int		is_sorted(t_stack *stack);
void	sort_left_3(t_stack **stack_a, t_stack **stack_b);
void	sort_3(t_stack **stack);

/* find */
void	find_target_pos(t_stack **stack_a, t_stack **stack_b);
int		find_highest(t_stack *stack);
int		find_lowest(t_stack *stack);

/* utils */
void	utils_calc_cost(t_stack **stack, int b);
void	utils_rotate(t_stack **stack, int cost, int a, int b);
void	utils_print(char *instruct_a, char *instruct_b, int a, int b);
size_t 	utils_absolutes(int num);
#endif