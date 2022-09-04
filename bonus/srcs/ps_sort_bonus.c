/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:31:37 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/04 10:40:07 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	init_func_1(func_one_stk funcs[])
{
	funcs[0] = do_swap;
	funcs[1] = do_rotate_left;
	funcs[2] = do_rotate_right;
	funcs[4] = NULL;
}

/*void	init_func_2(func_two_stks funcs[])
{
	//funcs[0] = do_swap;
	funcs[1] = rotate_both_left;
	funcs[2] = rotate_both_right;
	funcs[3] = NULL;
}*/

void	sort_stack(char *instruc, t_stk **stk_a, t_stk **stk_b)
{
	int				i;
	func_one_stk	move_1_stk[4];
	//func_two_stks	move_2_stks[5];
	const char		*instruc_1_stk[] = {"s", "r", "rr", "p", NULL};	
	//const char		*instruc_2_stks[] = {"ss", "rr", "rrr",  NULL};	

	i = -1;
	init_func_1(move_1_stk);
	while (instruc_1_stk[++i])
	{
		if (!ft_strncmp(instruc_1_stk[i], instruc, ft_strlen(instruc_1_stk[i])))
		{
			if (ft_strchr(instruc, 'p') && ft_strchr(instruc, 'a'))
				do_push(stk_b, stk_a, 0, 0);
			else if (ft_strchr(instruc, 'p') && ft_strchr(instruc, 'b'))
				do_push(stk_a, stk_b, 0, 0);
			else if (ft_strchr(instruc, 'a'))
			{
				//printf("%s |", instruc);
				move_1_stk[i](stk_a, 0, 0);

			}
			else if (ft_strchr(instruc, 'b'))
				move_1_stk[i](stk_b, 0, 0);
		}
	}
}
