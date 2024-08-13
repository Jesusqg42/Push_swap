/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:57:30 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/08/13 21:53:27 by jquiaro-         ###   ########.fr       */
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

int	index_data(int data, int *numbers)
{
	int	i;

	i = 0;
	while (numbers[i] != data)
		i++;
	return (i);
}

//the python tutor

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
  int     data;
  int     s_index;
  struct  s_node *next;
} t_node;

typedef struct s_stack
{
  t_node  *head;
  int     size;
} t_stack;

void  bubble_sort(int *numbers, int length)
{
  int temp;
  int i;
  int j;
  
  i = 1;
  while (i < length)
  {
    temp = numbers[i];
    j = i - 1;
    while (j >= 0 && numbers[j] > temp)
    {
      numbers[j + 1] = numbers[j];
      j--;
    }
    numbers[j + 1] = temp;
    i++;
  }
}

int index_of(int n, int *numbers)
{
  int i = 0;
  while (numbers[i] != n)
    i++;
  return (i);
} 

void  push_stack(t_stack *stack, int index, int data)
{
  t_node  *temp;
  
  temp = (t_node *)malloc(sizeof(t_node));
  if (!temp)
    return ;
  temp->data = data;
  temp->s_index = index;
  temp->next = stack->head;
  stack->head = temp;
  stack->size++;
}

void  init_stack(t_stack *stack_a, t_stack *stack_b, int *numbers, int length)
{
  t_node *temp; //the temporal node.
  
  stack_b->head = NULL;
  stack_a->head = NULL;
  stack_b->size = 0;
  stack_a->size = 0;
  
  int i = length - 1;
  
  while (i >= 0)
    push_stack(stack_a, 0, numbers[i--]);
  bubble_sort(numbers, length);
  temp = stack_a->head;
  while (temp)
  {
    temp->s_index = index_of(temp->data, numbers);
    temp = temp->next;
  }
}

int main(void)
{
  t_stack  stack_a;
  t_stack  stack_b;
  int numbers[] = {20, 5,10};
  int length = sizeof(numbers) / sizeof(int);
  
  init_stack(&stack_a, &stack_b, numbers, length);
  return (0);
}