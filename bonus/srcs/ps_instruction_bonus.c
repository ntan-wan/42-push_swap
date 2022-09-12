/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instruction_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:32:16 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/12 16:06:48 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	is_instruction(const char *instruc)
{
	int			i;
	int			instruc_len;
	const char	*instrucs[] = {"pa\n", "pb\n", "sa\n", \
	"sb\n", "ss\n", "ra\n", "rb\n", "rr\n", "rra\n", \
	"rrb\n", "rrr\n", NULL};

	i = -1;
	while (instrucs[++i])
	{
		instruc_len = ft_strlen(instruc);
		if (!ft_strncmp(instrucs[i], instruc, instruc_len))
			return (1);
	}
	return (0);
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

void	exec_instrucs(t_list *instrucs, t_stk **stk_a, t_stk **stk_b)
{
	t_list	*ptr_instrucs;

	ptr_instrucs = instrucs;
	while (ptr_instrucs)
	{
		sort_stack((char *)ptr_instrucs->content, stk_a, stk_b);
		ptr_instrucs = ptr_instrucs->next;
	}
}
