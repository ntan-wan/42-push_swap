/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:02:42 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/31 15:14:00 by ntan-wan         ###   ########.fr       */
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
	char	*int_num;
	char 	*char_num;

	char_num = str;
	int_num = ft_itoa(ft_atoi(str));
	while (is_sign(*int_num))
		int_num++;
	while (is_sign(*char_num) || *char_num == '0')
		char_num++;	
	if (ft_strncmp(int_num, char_num, ft_strlen(char_num)))
		return (0);
	return (1);
}

/*static int	have_duplicates(char **av)
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
}*/

static int	is_valid_zero(char *num)
{
	int	i;

	i = -1;
	if (num[0] == '-' && ft_atoi(num) == 0)
		return (0);
	return (1);
}

int	is_input(int ac, char **av)
{
	int	j;
	int	k;
	char	**input;

	(void)ac;
	j = 0;
	while (av[++j])
	{
		k = -1;
		input = ft_split(av[j], ' ');
		while (input[++k])
		{
			//
			//printf("%s |", input[k]);
			if (!is_valid_zero(input[k]))
			return (0);
			if (!is_number(input[k]))
			return (0);
			if (!in_int_range(input[k]))
			return (0);
			free(input[k]);
		}
		free(input);
	}
	return (1);
}