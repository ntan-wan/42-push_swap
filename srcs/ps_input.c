/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:02:42 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/26 11:39:52 by ntan-wan         ###   ########.fr       */
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

static int in_int_range(char *str)
{
	if (str[0] != '-' && ft_atoi(str) < 0)
		return (0);
	if (str[0] == '-' && ft_atoi(str) >= 0)
		return (0);
	return (1);
}

static int	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
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

int	is_input(char **av)
{
	int	i;

	i = 1;
	if (have_duplicates(av))
		return (0);
	while (av[i])
	{
		if (!is_number(av[i]))
			return (0);
		if (!in_int_range(av[i]))
			return (0);
		i++;
	}
	return (1);
}