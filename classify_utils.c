/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:54:38 by marvin            #+#    #+#             */
/*   Updated: 2024/08/29 17:24:59 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index(void)
{
	return (0);
}

int	count_range(t_node *stack, int minimun)
{
	int	range;

	range = 0;
	while (stack && stack->s_index != minimun)
	{
		stack = stack->next;
		range++;
	}
	return (range);
}
