/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:24:31 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/05 11:18:02 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

# define MIN_ARGS 1

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
}	t_stk;

/* input */
int		is_input(char **av);
int		get_input_size(char	**av);
void	free_input_arr(char ***arr);
char	**get_all_inputs(char **av, int size);

/* input_utils */
int		is_sign(char c);
int		is_number(char *str);
int		is_int_range(char *str);
int		is_dup(char **all_inputs);
void	error_exit(char *message);

/* stack */
int		stack_size(t_stk *stack);
t_stk	*stack_fill(char **av);
t_stk	*stack_find(t_stk *stack, t_stk *stopper);

/* init */
void	init_pos(t_stk *stack);
void	init_index(t_stk *stack, int size);
void	init_target_pos(t_stk **stk_a, t_stk **stk_b);

/* do */
void	do_swap(t_stk **stack);
void	do_push(t_stk **src, t_stk **dst);
void	do_rotate_left(t_stk **stack);
void	do_rotate_right(t_stk **stack);
void	do_and_print(t_stk **stk, void (*f)(t_stk **), char *instruc);

/* rotate_both */
void	swap_both(t_stk **stk_a, t_stk **stk_b);
void	rotate_both_left(t_stk **stk_a, t_stk **stk_b);
void	rotate_both_right(t_stk **stk_a, t_stk **stk_b);

/* sort */
int		is_sorted(t_stk *stack);
void	sort_left_3(t_stk **stk_a, t_stk **stk_b);
void	sort_3(t_stk **stack);

/* find */
int		find_highest_index(t_stk *stack);
int		find_lowest_index(t_stk *stack);
int		find_target_index(t_stk **stk_a, t_stk *ptr_b);
t_stk	*find_target_i(t_stk **stack, int target_index);
t_stk	*find_target_c(t_stk **stack, int cost, int b);

/* utils */
size_t	utils_abs(int num);
void	utils_calc_cost(t_stk **stack, int b);
void	utils_rotate_to_top(t_stk **stack, t_stk *target, int a);
void	utils_print(char *instruct_a, char *instruct_b, int a, int b);
void	utils_free_stack(t_stk **stack);

#endif