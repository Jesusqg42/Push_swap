/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:03:07 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/08/14 23:47:52 by jquiaro-         ###   ########.fr       */
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
	while (ft_space(str[i]))
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

void	bubble_sort(int *numbers, int count)
{
	int	temp;
	int	i;
	int	j;

	i = 1;
	while (i < count)
	{
		temp = numbers[i];
		j = i - 1;
		while (j >= 0 && numbers[j] > temp)
		{
			numbers[j + 1] = numbers[j];
			j -= 1;
		}
		numbers[j + 1] = temp;
		i++;
	}
}
