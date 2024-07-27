/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:08:09 by marvin            #+#    #+#             */
/*   Updated: 2024/04/12 15:11:47 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dup == NULL)
		return (0);
	ft_strlcpy(dup, s1, ft_strlen(s1) + 1);
	return (dup);
}
