/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:15:57 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/05 11:56:32 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	print_instructions(t_list *instructions)
{
	while (instructions)
	{
		printf("%s", (char *)instructions->content);
		instructions = instructions->next;
	}	
}

void	print_stack(t_stk *stk)
{
	while (stk)
	{
		printf("%d|", stk->value);
		stk = stk->next;
	}	
	printf("\n");
}

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
		execute_instructions(instructions, &stk_a, &stk_b);
		print_stack(stk_a);
		print_stack(stk_b);
		//print_instructions(instructions);
		utils_free_stack(&stk_a);
		utils_free_stack(&stk_b);
		ft_lstclear(&instructions, free);
	}
	system("leaks checker");
	return (0);
}