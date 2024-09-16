/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:03:31 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/09/16 02:43:44 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(int *numbers, int count)
{
	int		i;
	int		j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_digits(int argc, char **argv)
{
    int	i;
    int	j;
    int	count;

    i = 1;
    count = 0;
    while (i < argc)
    {
        j = 0;
        if (argv[i][j] == '\0')
            return (-1);
        while (argv[i][j])
        {
            if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ' && \
                argv[i][j] != '-' && argv[i][j] != '+')
                return (-1);
            if ((argv[i][j] == '-' || argv[i][j] == '+') && \
                !ft_isdigit(argv[i][j + 1]))
                return (-1);
            if (ft_isdigit(argv[i][j]) && (argv[i][j + 1] == ' ' || \
                argv[i][j + 1] == '\0'))
                if (!ft_isdigit(argv[i][j + 1]))
                    count++;
            j++;
        }
        i++;
    }
    return (count);
}

void	check_range(char **list_numbers, int *numbers)
{
	int	i;

	i = 0;
	while (list_numbers[i])
	{
		if (ft_atoll(list_numbers[i]) > INT_MAX || \
			ft_atoll(list_numbers[i]) < INT_MIN || \
			ft_strlen(list_numbers[i]) > 11)
		{
			ft_free2d(list_numbers);
			free(numbers);
			ft_printf("Error\n");
			exit(1);
		}
		i++;
	}
}

int	*store_digits(int argc, char **argv, int count)
{
	char	**list_numbers;
	int		*numbers;
	int		i;
	int		j;
	int		k;

	numbers = (int *)malloc(sizeof(int) * count);
	if (!numbers)
		return (0);
	i = 1;
	j = 0;
	while (i < argc)
	{
		list_numbers = ft_split(argv[i], ' ');
		if (!list_numbers)
			exit(1);
		check_range(list_numbers, numbers);
		k = 0;
		while (list_numbers[k])
			numbers[j++] = ft_atoi(list_numbers[k++]);
		ft_free2d(list_numbers);
		i++;
	}
	return (numbers);
}
