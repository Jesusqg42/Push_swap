/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:54:25 by marvin            #+#    #+#             */
/*   Updated: 2024/09/18 23:54:59 by jquiaro-         ###   ########.fr       */
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

void	musketeers(t_stack *stack, int count)
{
	int	minimun;
	int	range;

	if (stack_tidy(stack))
		return ;
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
	int	minimun;
	int	length;
	int	i;

	i = 0;
	length = count;
	while (i++ < length - 3)
	{
		minimun = min_index(stack_a);
		if (count_range(stack_a->head, minimun) < length / 2)
			while (stack_a->head->s_index != minimun)
				rotate(stack_a, 'a');
		else
			while (stack_a->head->s_index != minimun)
				reverse_rotate(stack_a, 'a');
		if (stack_tidy(stack_a) && stack_b->size == 0)
			return ;
		push(stack_a, stack_b, 'b');
		count--;
	}
	musketeers(stack_a, count);
	i = 0;
	while (i++ < length - 3)
		push(stack_b, stack_a, 'a');
}

void	quicksort_dp_one(t_stack *stack_a, t_stack *stack_b, int count)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(count) * 14 / 10;
	while (stack_a->head)
	{
		if (stack_a->head->s_index <= i)
		{
			push(stack_a, stack_b, 'b');
			rotate(stack_b, 'b');
			i++;
		}
		else if (stack_a->head->s_index <= i + range)
		{
			push(stack_a, stack_b, 'b');
			i++;
		}
		else
			rotate(stack_a, 'a');
	}
}

void	quicksort_dp_two(t_stack *stack_a, t_stack *stack_b, int count)
{
	int	rb_count;
	int	rrb_count;

	while (count - 1 >= 0)
	{
		rb_count = count_range(stack_b->head, count - 1);
		rrb_count = (count + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->head->s_index != count - 1)
				rotate(stack_b, 'b');
			push(stack_b, stack_a, 'a');
			count--;
		}
		else
		{
			while (stack_b->head->s_index != count - 1)
				reverse_rotate(stack_b, 'b');
			push(stack_b, stack_a, 'a');
			count--;
		}
	}
}
