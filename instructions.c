/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:46:12 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/09/09 18:33:13 by jquiaro-         ###   ########.fr       */
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

void	push(t_stack *stack_main, t_stack *stack_support, char character)
{
	int	s_index;

	if (stack_main->head == NULL)
		return ;
	s_index = stack_main->head->s_index;
	push_stack(stack_support, s_index, pop_stack(stack_main));
	ft_printf("p%c\n", character);
}
