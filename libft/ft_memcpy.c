/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:09:24 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/03/21 18:31:43 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*copy;
	char	*original;

	copy = (char *)dst;
	original = (char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	while (i < n)
	{
		copy[i] = original[i];
		i++;
	}
	return (dst);
}
