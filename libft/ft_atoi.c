/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:19:37 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/07/27 18:11:31 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static int	ft_space(char c)
{
	return (
		c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r'
	);
}

int32_t	ft_atoi(const char *str)
{
	size_t	i;
	int32_t	sign;
	int32_t	out;

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
