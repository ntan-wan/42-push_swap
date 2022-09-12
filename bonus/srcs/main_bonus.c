/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:15:57 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/12 16:12:22 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int ac, char **av)
{
	t_stk	*stk_a;
	t_stk	*stk_b;
	t_list	*instructions;

	if (ac > MIN_ARGS)
	{
		if (!is_input(av))
			error_exit("Error\n");
		stk_a = stack_fill(av);
		stk_b = NULL;
		instructions = get_instructions();
		exec_instrucs(instructions, &stk_a, &stk_b);
		print_result(&stk_a, &stk_b);
		utils_free_stack(&stk_a);
		utils_free_stack(&stk_b);
		ft_lstclear(&instructions, free);
	}
	return (0);
}
