/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:54:38 by marvin            #+#    #+#             */
/*   Updated: 2024/08/29 19:28:30 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index(t_stack *stack)
{
	t_node	*temp;
	int		minimun;

	temp = stack->head;
	minimun = temp->s_index;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->s_index < minimun)
			minimun = temp->s_index;
	}
	return (minimun);
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
