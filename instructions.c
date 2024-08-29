/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:46:12 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/08/29 17:12:38 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char character)
{
	t_node	*temp;

	temp = stack->head;
	stack->head = temp->next;
	temp->next = stack->head->next;
	stack->head->next = temp;
	ft_printf("s%c\n", character);
}

void	rotate(t_stack *stack, char character)
{
	t_node	*temp;
	t_node	*current;

	temp = stack->head;
	stack->head = temp->next;
	current = stack->head;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
	temp->next = NULL;
	ft_printf("r%c\n", character);
}

void	reverse_rotate(t_stack *stack, char character)
{
	t_node	*temp;
	t_node	*current;

	current = stack->head;
	while (current->next->next != NULL)
		current = current->next;
	temp = current->next;
	current->next = NULL;
	temp->next = stack->head;
	stack->head = temp;
	ft_printf("rr%c\n", character);
}
