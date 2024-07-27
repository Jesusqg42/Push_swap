/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:45:00 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/04/03 11:19:58 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	value;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	value = len;
	if (len > ft_strlen(haystack))
		value = ft_strlen(haystack);
	while (value >= ft_strlen(needle))
	{
		if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
			return ((char *)haystack);
		haystack++;
		value--;
	}
	return (0);
}
