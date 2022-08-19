/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:24:31 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/19 15:46:51 by ntan-wan         ###   ########.fr       */
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
t_stack	*stack_fill(char **av);
t_stack *stack_get_top(t_stack *stack);

/* init */
void	init_index(int ac, t_stack *stack);
void	init_pos(t_stack *stack);

/* do */
void	do_sa(t_stack **stack);
void    do_ra(t_stack **stack);
void	do_rra(t_stack **stack);
/* sort */
void	sort_2(t_stack **stack);
void	sort_3(int ac, t_stack **stack);
#endif