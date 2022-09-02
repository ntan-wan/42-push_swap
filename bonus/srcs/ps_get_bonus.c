/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:32:16 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/02 11:37:37 by ntan-wan         ###   ########.fr       */
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
		instruction = get_next_line(STDIN);
		if (!instruction)
			break ;
		temp = ft_lstnew(instruction);
		ft_lstadd_back(&instructions, temp);
	}
	return (instructions);
}