/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:42:17 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/08/26 23:42:51 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		count;
	int		*numbers;

	if (argc == 1)
		exit(1);
	count = check_digits(argc, argv);
	numbers = store_digits(argc, argv, count);
	if (count <= 1 || check_duplicates(numbers, count))
	{
		free(numbers);
		if (count == 1)
			exit(1);
		ft_printf("Error\n");
		exit(1);
	}
	init_stack(&stack_a, &stack_b, numbers, count);
	sort(&stack_a, &stack_b, numbers, count);
	free(numbers);
	free_stack(&stack_a);
	return (0);
}

void	init_stack(t_stack *stack_a, t_stack *stack_b, int *numbers, int count)
{
	t_node	*temp;
	int		i;

	stack_a->head = NULL;
	stack_a->size = 0;
	stack_b->head = NULL;
	stack_b->size = 0;
	i = count - 1;
	while (i >= 0)
	{
		push_stack(stack_a, 0, numbers[i]);
		i--;
	}
	bubble_sort(numbers, count);
	temp = stack_a->head;
	while (temp)
	{
		temp->s_index = index_data(temp->data, numbers);
		temp = temp->next;
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b, int *numbers, int count)
{
	if (stack_tidy(stack_a))
	{
		free(numbers);
		free_stack(stack_a);
		exit(1);
	}
	else if (count == 2)
		swap(stack_a,'a');
	else if (count == 3)
		musketeers_sort(stack_a, count);
	else
		exit(1);
}

//TESTS

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
  int data;
  struct s_node *next;
} t_node;

typedef struct s_stack
{
  t_node *head;
  int size;
} t_stack;

void    swap(t_stack *stack)
{
    t_node    *temp;

    temp = stack->head;
    stack->head = temp->next;
    temp->next = stack->head->next;
    stack->head->next = temp;
    printf("sa");
}

void push_stack(t_stack *stack, int index, int data)
{
  t_node *temp;

  temp = (t_node *)malloc(sizeof(t_node));
  if (!temp)
    return;
  temp->data = data;
  temp->next = stack->head;
  stack->head = temp;
  stack->size++;
}

int main(void)
{
  t_stack stack_a; 
  int numbers[] = {2, 1, 3};
  
  stack_a.head = NULL;
  stack_a.size = 0;
  int length = sizeof(numbers) / sizeof(int);

  int i = length - 1;
  while (i >= 0)
    push_stack(&stack_a, 0, numbers[i--]);
    
  if (length == 3)
    swap(&stack_a);
  return 0;
}
