/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:38:58 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/05 13:10:03 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include "../../libft/libft.h"

# define STDIN 0
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

/* function pointer */
typedef void	(*t_func_do_1_stk)(t_stk **);
typedef void	(*t_func_do_2_stks)(t_stk **, t_stk **);

/* instruction */
t_list	*get_instructions(void);
void	exec_instrucs(t_list *instructions, t_stk **stk_a, t_stk **stk_b);

/* input */
int		is_input(char **av);

/* do */
void	do_swap(t_stk **stack);
void	do_rotate_left(t_stk **stack);
void	do_rotate_right(t_stk **stack);
void	do_push(t_stk **src, t_stk **dst);

/* rotate_both */
void	swap_both(t_stk **stk_a, t_stk **stk_b);
void	rotate_both_left(t_stk **stk_a, t_stk **stk_b);
void	rotate_both_right(t_stk **stk_a, t_stk **stk_b);

/* sort */
int		is_sorted(t_stk *stack);

/* sort_bonus */
void	sort_stack(char *instruc, t_stk **stk_a, t_stk **stk_b);

/* stack */
t_stk	*stack_fill(char **av);
int		stack_size(t_stk *stack);

/* init */
void	init_index(t_stk *stack, int size);

/* input_utils */
void	error_exit(char *message);

/* utils */
void	utils_free_stack(t_stk **stack);

/* utils_bonus */
void	print_stack(t_stk *stk);
void	print_instructions(t_list *instructions);
void	print_result(t_stk **stk_a, t_stk **stk_b);
#endif