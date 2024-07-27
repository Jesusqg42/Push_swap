/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:50:59 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/04/26 20:10:22 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	inword;

	count = 0;
	inword = 0;
	while (*s)
	{
		if (*s == c)
			inword = 0;
		else if (!inword)
		{
			inword = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static void	*free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		i;
	char	**strs;

	count = ft_count_words(s, c);
	if (!s)
		return (0);
	strs = (char **)malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (0);
	strs[count] = NULL;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			strs[i] = ft_substr(s, 0, ft_wordlen(s, c));
			if (!strs[i++])
				return (free_strs(strs));
			s += ft_wordlen(s, c);
		}
		else
			s++;
	}
	return (strs);
}
