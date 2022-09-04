/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:31:37 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/05 06:34:13 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	get_size_arr_str(const char **arr)
{
	int	size;

	size = 0;
	while (*arr++)
		size++;
	return (size);
}

void	init_func_1(func_one_stk funcs[])
{
	funcs[0] = do_swap;
	funcs[1] = do_rotate_left;
	funcs[2] = do_rotate_right;
	funcs[3] = NULL;
}

void	init_func_2(func_two_stks funcs[])
{
	//funcs[0] = do_swap;
	funcs[1] = rotate_both_left;
	funcs[2] = rotate_both_right;
	funcs[3] = do_push;
	funcs[4] = NULL;
}


void	sort_stack(const char *instruc, t_stk **stk_a, t_stk **stk_b)
{
	int				i;
	func_one_stk	move_1_stk[4];
	func_two_stks	move_2_stks[5];
	const char		*instruc_1_stk[] = \
	{"sa\n", "ra\n", "rra\n", "sb\n", "rb\n", "rrb\n", NULL};	
	const char		*instruc_2_stks[] = \
	{"ss\n", "rr\n", "rrr\n", "pa\n", "pb\n", NULL};

	i = -1;
	init_func_1(move_1_stk);
	while (instruc_1_stk[++i])
	{
		if (!ft_strncmp(instruc_1_stk[i], instruc, ft_strlen(instruc)))
		{
			if (ft_strchr(instruc, 'a'))
				move_1_stk[i](stk_a);
			else if (ft_strchr(instruc, 'b'))
				move_1_stk[i - 3](stk_b);
		}
	}
	i = -1;
	init_func_2(move_2_stks);
	while (instruc_2_stks[++i])
	{
		if (!ft_strncmp(instruc_2_stks[i], instruc, ft_strlen(instruc)))
		{
			if (ft_strchr(instruc, 'a'))
				move_2_stks[i](stk_b, stk_a);
			else if (ft_strchr(instruc, 'b'))
				move_2_stks[i - 1](stk_a, stk_b);
			else
				move_2_stks[i](stk_a, stk_b);
		}
	}
}
