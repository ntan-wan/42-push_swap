/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:02:42 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/01 09:24:29 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

static int	is_number(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

static int	in_int_range(char *str)
{
	char	*int_num;
	char	*char_num;

	char_num = str;
	int_num = ft_itoa(ft_atoi(str));
	while (is_sign(*int_num))
		int_num++;
	while (is_sign(*char_num) || *char_num == '0')
		char_num++;
	if (ft_strncmp(int_num, char_num, ft_strlen(char_num)))
	{
		free(int_num);
		return (0);
	}
	free(int_num);
	return (1);
}

static int	is_duplicates(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) - ft_atoi(av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_valid_zero(char *num)
{
	int	i;

	i = -1;
	if (num[0] == '-' && ft_atoi(num) == 0)
		return (0);
	return (1);
}

void	free_char_arr(char ***arr)
{
	int	i;

	i = -1;
	while ((*arr)[++i])
		free((*arr)[i]);
	free(*arr);
}

static int	have_duplicates(char **av, int *count)
{
	int		i;
	int		j;
	int		k;
	char	**input;
	char	**all_inputs;

	i = 0;
	k = -1;
	all_inputs = malloc(sizeof(char *) * ((*count) + 1));
	all_inputs[*count] = NULL;
	while (av[++i])
	{	
		j = -1;
		input = ft_split(av[i], ' ');
		while (input[++j])
			all_inputs[++k] = input[j];
		free(input);
	}
	if (is_duplicates(all_inputs))
	{
		free_char_arr(&all_inputs);
		return (1);
	}
	free_char_arr(&all_inputs);
	return (0);
}

int	is_input(char **av)
{
	int		i;
	int		j;
	int		count;
	char	**input;
	char	**all_inputs;

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
			if (!in_int_range(input[j]))
				return (0);
			count++;
			free(input[j]);
		}
		free(input);
	}
	if (have_duplicates(av, &count))
		return (0);
	return (1);
}
