/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:31:37 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/05 13:03:12 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	init_func_1(t_func_do_1_stk funcs[])
{
	funcs[0] = do_swap;
	funcs[1] = do_rotate_left;
	funcs[2] = do_rotate_right;
	funcs[3] = do_swap;
	funcs[4] = do_rotate_left;
	funcs[5] = do_rotate_right;
	funcs[6] = NULL;
}

static void	init_func_2(t_func_do_2_stks funcs[])
{
	funcs[0] = swap_both;
	funcs[1] = rotate_both_left;
	funcs[2] = rotate_both_right;
	funcs[3] = do_push;
	funcs[4] = do_push;
	funcs[5] = NULL;
}

static void	do_1_stk(t_stk **stk_a, t_stk **stk_b, \
char *instruc, void (*funcs)(t_stk **))
{
	if (ft_strchr(instruc, 'a'))
		funcs(stk_a);
	else if (ft_strchr(instruc, 'b'))
		funcs(stk_b);
}

static void	do_2_stks(t_stk **stk_a, t_stk **stk_b, \
char *instruc, void (*funcs)(t_stk **, t_stk **))
{
	if (ft_strchr(instruc, 'a'))
		funcs(stk_b, stk_a);
	else if (ft_strchr(instruc, 'b'))
		funcs(stk_a, stk_b);
	else
		funcs(stk_a, stk_b);
}

void	sort_stack(char *instruc, t_stk **stk_a, t_stk **stk_b)
{
	int					i;
	t_func_do_1_stk		funcs_stk[7];
	t_func_do_2_stks	funcs_stks[6];
	const char			*instrucs_1_stk[] = \
	{"sa\n", "ra\n", "rra\n", "sb\n", "rb\n", "rrb\n", NULL};
	const char			*instrucs_2_stks[] = \
	{"ss\n", "rr\n", "rrr\n", "pa\n", "pb\n", NULL};

	i = -1;
	init_func_1(funcs_stk);
	while (instrucs_1_stk[++i])
	{
		if (!ft_strncmp(instrucs_1_stk[i], instruc, ft_strlen(instruc)))
			do_1_stk(stk_a, stk_b, instruc, funcs_stk[i]);
	}
	i = -1;
	init_func_2(funcs_stks);
	while (instrucs_2_stks[++i])
	{
		if (!ft_strncmp(instrucs_2_stks[i], instruc, ft_strlen(instruc)))
			do_2_stks(stk_a, stk_b, instruc, funcs_stks[i]);
	}
}
