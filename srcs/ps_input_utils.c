/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:34:19 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/12 16:04:25 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_exit(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i]) && str[i + 1] != '\0')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	is_int_range(char *str)
{
	int		i;
	char	*int_num;
	char	*char_num;

	i = 0;
	char_num = str;
	int_num = ft_itoa(ft_atoi(str));
	while (is_sign(int_num[i]))
		i++;
	while (is_sign(*char_num) || *char_num == '0')
		char_num++;
	if (ft_strncmp(&int_num[i], char_num, ft_strlen(char_num)))
	{
		free(int_num);
		return (0);
	}
	free(int_num);
	return (1);
}

int	is_dup(char **all_inputs)
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
