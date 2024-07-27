/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:19:19 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/04/25 16:14:04 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	result;

	result = (long long int)n;
	if (result < 0)
	{
		write(fd, "-", 1);
		result = -result;
	}
	if (result > 9)
	{
		ft_putnbr_fd(result / 10, fd);
		ft_putchar_fd(48 + (result % 10), fd);
	}
	else
		ft_putchar_fd(48 + result, fd);
}
