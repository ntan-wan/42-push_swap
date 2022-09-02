/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instruction_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:32:16 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/02 12:17:16 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	is_instruction(char *instruction)
{
	if (ft_strncmp("pa\n", instruction, 3))
		return (0);
	if (ft_strncmp("pb\n", instruction, 3))
		return (0);
	if (ft_strncmp("sa\n", instruction, 3))
		return (0);
	if (ft_strncmp("sb\n", instruction, 3))
		return (0);
	if (ft_strncmp("ss\n", instruction, 3))
		return (0);
	if (ft_strncmp("ra\n", instruction, 3))
		return (0);
	if (ft_strncmp("rb\n", instruction, 3))
		return (0);
	if (ft_strncmp("rr\n", instruction, 3))
		return (0);
	if (ft_strncmp("rra\n", instruction, 4))
		return (0);
	if (ft_strncmp("rrb\n", instruction, 4))
		return (0);
	if (ft_strncmp("rrr\n", instruction, 4))
		return (0);
	return (1);
}

t_list	*get_instructions(void)
{
	char	*instruction;
	t_list	*instructions;
	t_list	*temp;

	instructions = NULL;
	while (1)
	{
		instruction = get_next_line(STDIN);
		if (!instruction)
			break ;
		if (!is_instruction(instruction))
			error_exit("Error\n");
		temp = ft_lstnew(instruction);
		ft_lstadd_back(&instructions, temp);
	}
	return (instructions);
}


void	execute_instructions(t_list *instructions, t_stk **stk)
{
	t_list	*ptr_instructions;
	(void)stk;
	ptr_instructions = instructions;
	while (ptr_instructions)
	{
		ptr_instructions = ptr_instructions->next;
	}
}
