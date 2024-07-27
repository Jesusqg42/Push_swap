/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:24:13 by marvin            #+#    #+#             */
/*   Updated: 2024/04/01 16:32:26 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_len;

	s_len = ft_strlen(s);
	if ((char)c == '\0' && s[s_len] == '\0')
		return (&((char *)s)[s_len]);
	while (s_len > 0)
	{
		s_len--;
		if ((char)c == s[s_len])
			return (&((char *)s)[s_len]);
	}
	return (0);
}
