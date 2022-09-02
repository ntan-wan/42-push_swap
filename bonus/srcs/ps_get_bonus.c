/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:32:16 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/02 10:44:21 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_list	*get_instructions(void)
{
	char	*instruction;
	t_list	*instructions;
	t_list	*temp;

	instructions = NULL;
	while (1)
	{
		//remember to free
		instruction = get_next_line(STDIN);
		if (!instruction)
			break ;
		//remember to free
		temp = ft_lstnew(instruction);
		ft_lstadd_back(&instructions, temp);
	}
	return (instructions);
}