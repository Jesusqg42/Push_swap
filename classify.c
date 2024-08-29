/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:54:25 by marvin            #+#    #+#             */
/*   Updated: 2024/08/29 19:24:51 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_sort(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->head->data;
	b = stack->head->next->data;
	c = stack->head->next->next->data;
	if (b < c && a > c)
		return (1);
	else if (c < a && a < b)
		return (1);
	return (0);
}

void	musketeers_sort(t_stack *stack, int count)
{
	int	minimun;
	int	range;

	minimun = min_index(stack);
	range = count_range(stack->head, minimun);
	if (rotate_sort(stack))
	{
		if (range < count - range)
			rotate(stack, 'a');
		else
			reverse_rotate(stack, 'a');
	}
	else
	{
		swap(stack, 'a');
		if (stack_tidy(stack))
			return ;
		else if (range < count - range)
			rotate(stack, 'a');
		else
			reverse_rotate(stack, 'a');
	}
}

void	dwarfs(t_stack *stack_a, t_stack *stack_b, int count)
{
	
}