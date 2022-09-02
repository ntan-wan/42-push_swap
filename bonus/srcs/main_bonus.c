/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:15:57 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/02 10:43:45 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int ac, char **av)
{
	/*t_stk	*stk_a;
	t_list	*instructions;

	if (ac > MIN_ARGS)
	{
		if (!is_input(av))
			error_exit("Error\n");
		//stk_a = stack_fill(av);
		instructions = get_instructions();
		while (instructions)
		{
			printf("%s\n", (char *)instructions->content);
			instructions = instructions->next;
		}
		//utils_free_stack(&stk_a);
	}*/
	(void)ac;
	(void)av;
	/*char	*instruction;
	t_list	*instructions;
	t_list	*temp;
	
	instructions = NULL;
	while (1)
	{	//remember to free
		instruction = get_next_line(STDIN);
		if (!instruction)
			break ;
		//remember to free
		temp = ft_lstnew(instruction);
		ft_lstadd_back(&instructions, temp);
		//free(instruction);
	}*/
	t_list	*instructions;

	instructions = get_instructions();
	while (instructions)
	{
		printf("%s", (char *)instructions->content);
		instructions = instructions->next;
	}
	return (0);
}