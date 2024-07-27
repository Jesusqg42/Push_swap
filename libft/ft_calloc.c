/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:19:14 by marvin            #+#    #+#             */
/*   Updated: 2024/04/05 15:19:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*calloc_d;

	calloc_d = (void *)malloc(count * size);
	if (calloc_d == NULL)
		return (0);
	ft_memset(calloc_d, 0, count * size);
	return (calloc_d);
}
