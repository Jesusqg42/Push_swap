/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:03:07 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/07/27 21:10:50 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int64_t	ft_atoll(const char *str)
{
	size_t	i;
	int32_t	sign;
	int64_t	out;

	i = 0;
	sign = 1;
	out = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		out = (out * 10) + (str[i++] - '0');
	return (out * sign);
}

void	ft_free2d(char **str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str && str[i])
		{
			if (str[i] != NULL)
			{
				free(str[i]);
				str[i] = NULL;
			}
			i++;
		}
		free(str);
		str = NULL;
	}
}
