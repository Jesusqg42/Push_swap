/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:54:25 by marvin            #+#    #+#             */
/*   Updated: 2024/08/26 23:32:10 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rotate_sort(t_stack *stack, int minimun)
{
    int a;
    int b;
    int c;

    (void)minimun;
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
    int minimun;
    int range;

    minimun = min_index(stack);
    range = count_range(stack->head, minimun);
    if (rotate_sort(stack, minimun))
    {
        if (range < count - range)
            rotate(stack, 'a'); 
        else
            reverse_rotate(stack, 'a');
    }
    else
    {
        
    }
}
