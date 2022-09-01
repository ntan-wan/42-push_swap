/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:34:19 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/01 10:15:21 by ntan-wan         ###   ########.fr       */
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

static int	is_duplicates(char **all_inputs)
{
	int	i;
	int	j;

	i = 0;
	while (all_inputs[i])
	{
		j = i + 1;
		while (all_inputs[j])
		{
			if (ft_atoi(all_inputs[i]) - ft_atoi(all_inputs[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static char	**get_all_inputs(char **av, int count)
{
	int		i;
	int		j;
	int		k;
	char	**input;
	char	**all_inputs;
	
	i = 0;
	j = -1;
	all_inputs = malloc(sizeof(char *) * (count + 1));
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

int	have_duplicates(char **av, int *count)
{
	char	**all_inputs;

	all_inputs = get_all_inputs(av, *count);
	if (is_duplicates(all_inputs))
	{
		free_input_arr(&all_inputs);
		return (1);
	}
	free_input_arr(&all_inputs);
	return (0);
}