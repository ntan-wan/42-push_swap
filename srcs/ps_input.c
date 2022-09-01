/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:02:42 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/01 11:31:13 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_input_arr(char ***arr)
{
	int	i;

	i = -1;
	while ((*arr)[++i])
		free((*arr)[i]);
	free(*arr);
}

char	**get_all_inputs(char **av, int size)
{
	int		i;
	int		j;
	int		k;
	char	**input;
	char	**all_inputs;

	i = 0;
	j = -1;
	all_inputs = malloc(sizeof(char *) * (size + 1));
	all_inputs[count] = NULL;
	while (av[++i])
	{	
		k = -1;
		input = ft_split(av[i], ' ');
		while (input[++k])
			all_inputs[++j] = input[k];
		free(input);
	}
	return (all_inputs);
}

int	is_input(char **av)
{
	int		i;
	int		j;
	int		count;
	char	**input;

	i = 0;
	count = 0;
	while (av[++i])
	{
		j = -1;
		input = ft_split(av[i], ' ');
		while (input[++j])
		{
			if (!is_valid_zero(input[j]))
				return (0);
			if (!is_number(input[j]))
				return (0);
			if (!is_int_range(input[j]))
				return (0);
			count++;
			free(input[j]);
		}
		free(input);
	}
	if (dup_check(av, &count))
		return (0);
	return (1);
}
