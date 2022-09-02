/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:38:58 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/02 10:18:15 by ntan-wan         ###   ########.fr       */
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

int		is_input(char **av);
t_stk	*stack_fill(char **av);
t_list	*get_instructions(void);
void	error_exit(char *message);
void	utils_free_stack(t_stk **stack);

#endif