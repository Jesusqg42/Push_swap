/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:57:30 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/08/21 16:46:10 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *stack, int index, int data)
{
	t_node	*temp;

	temp = (t_node *)malloc(sizeof(t_node));
	if (!temp)
		return ;
	temp->data = data;
	temp->s_index = index;
	temp->next = stack->head;
	stack->head = temp;
	stack->size++;
}

int	pop_stack(t_stack *stack)
{
	t_node	*temp;
	int		data;

	if (!stack->head)
		exit(1);
	temp = stack->head;
	data = temp->data;
	stack->head = temp->next;
	free(temp);
	temp = NULL;
	stack->size--;
	return (data);
}

void	free_stack(t_stack *stack)
{
	while (stack)
		pop_stack(stack);
}

int	index_data(int data, int *numbers)
{
	int	i;

	i = 0;
	while (numbers[i] != data)
		i++;
	return (i);
}

int	stack_tidy(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}
