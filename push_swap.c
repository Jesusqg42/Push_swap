/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:42:17 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/08/13 16:41:19 by jquiaro-         ###   ########.fr       */
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

	stack_b->head = NULL;
	stack_a->head = NULL;
	stack_b->size = 0;
	stack_a->size = 0;
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
