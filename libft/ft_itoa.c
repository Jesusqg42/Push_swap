/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:24:06 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/04/25 19:27:53 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		count++;
	while (num != 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	long	temp;
	char	*result;

	len = numlen(n);
	temp = n;
	result = (char *)ft_calloc(len + 1, sizeof(char));
	if (result == 0)
		return (NULL);
	if (temp == 0)
	{
		result[--len] = '0';
		return (result);
	}
	if (temp < 0)
	{
		result[0] = '-';
		temp *= -1;
	}
	while (temp > 0)
	{
		result[--len] = '0' + (temp % 10);
		temp /= 10;
	}
	return (result);
}
