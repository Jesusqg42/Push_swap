/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:56:08 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/09/18 16:30:59 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	int				s_index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

/* ************************************************************************** */
/*                                   MAIN                                     */
/* ************************************************************************** */
int		main(int argc, char **argv);
void	init_stack(t_stack *stack_a, t_stack *stack_b, int *numbers, int count);
void	sort(t_stack *stack_a, t_stack *stack_b, int *numbers, int count);
/* ************************************************************************** */
/*                                CHECK_DIGITS                                */
/* ************************************************************************** */
int		check_digits(int argc, char **argv);
void	check_range(char **list_numbers, int *numbers);
int		check_duplicates(int *numbers, int count);
int		*store_digits(int argc, char **argv, int count);
/* ************************************************************************** */
/*                               PUSH_SWAP_UTILS                              */
/* ************************************************************************** */
int64_t	ft_atoll(const char *str);
void	ft_free2d(char **str);
void	bubble_sort(int *numbers, int count);
int		ft_sqrt(int number);
/* ************************************************************************** */
/*                                STACK_UTILS                                 */
/* ************************************************************************** */
void	push_stack(t_stack *stack, int index, int data);
int		pop_stack(t_stack *stack);
int		index_data(int data, int *numbers);
int		stack_tidy(t_stack *stack);
void	free_stack(t_stack *stack);
/* ************************************************************************** */
/*                               INSTRUCTIONS                                 */
/* ************************************************************************** */
void	swap(t_stack *stack, char character);
void	rotate(t_stack *stack, char character);
void	reverse_rotate(t_stack *stack, char character);
void	push(t_stack *stack_main, t_stack *stack_support, char character);
/* ************************************************************************** */
/*                                 CLASSIFY                                   */
/* ************************************************************************** */
int		rotate_sort(t_stack *stack);
void	musketeers(t_stack *stack, int count);
void	dwarfs(t_stack *stack_a, t_stack *stack_b, int count);
void	quicksort_dp_one(t_stack *stack_a, t_stack *stack_b, int count);
void	quicksort_dp_two(t_stack *stack_a, t_stack *stack_b, int count);
/* ************************************************************************** */
/*                              CLASSIFY_UTILS                                */
/* ************************************************************************** */
int		min_index(t_stack *stack);
int		count_range(t_node *stack, int index);

#endif