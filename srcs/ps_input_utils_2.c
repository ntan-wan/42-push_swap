/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:20:09 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/01 11:20:41 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	dup_check(char **av, int *count)
{
	char	**all_inputs;

	all_inputs = get_all_inputs(av, *count);
	if (is_dup(all_inputs))
	{
		free_input_arr(&all_inputs);
		return (1);
	}
	free_input_arr(&all_inputs);
	return (0);
}
