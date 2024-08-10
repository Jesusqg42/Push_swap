/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:42:17 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/08/10 22:14:07 by jquiaro-         ###   ########.fr       */
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
	t_node	*tmp;
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
	tmp = stack_a->head;
	while (tmp)
	{
		tmp->s_index = index_of(tmp->data, numbers);
		tmp = tmp->next;
	}
}
