/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:02:42 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/11/10 09:22:28 by ntan-wan         ###   ########.fr       */
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

int	get_input_size(char	**av)
{
	int		i;
	int		j;
	int		size;
	char	**input;

	i = 0;
	size = 0;
	while (av[++i])
	{
		j = -1;
		input = ft_split(av[i], ' ');
		while (input[++j])
		{
			free(input[j]);
			size++;
		}
		free(input);
	}
	return (size);
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
	all_inputs[size] = NULL;
	while (av[++i])
	{	
		if (av[i][0] == '\0')
		{
			free(all_inputs);
			error_exit("Error\n");
		}
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
	int		validity;
	char	**inputs;

	i = -1;
	validity = 1;
	inputs = get_all_inputs(av, get_input_size(av));
	if (is_dup(inputs))
		validity = 0;
	while (inputs[++i])
	{
		if (!is_number(inputs[i]))
			validity = 0;
		if (!is_int_range(inputs[i]))
			validity = 0;
	}
	free_input_arr(&inputs);
	return (validity);
}
