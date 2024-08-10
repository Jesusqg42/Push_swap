/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:56:08 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/08/10 21:14:42 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
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

int		main(int argc, char **argv);
int		check_digits(int argc, char **argv);
void	check_range(char **list_numbers, int *numbers);
int		*store_digits(int argc, char **argv, int count);
int		check_duplicates(int *numbers, int count);
int64_t	ft_atoll(const char *str);
void	ft_free2d(char **str);
void	init_stack(t_stack *stack_a, t_stack *stack_b, int *numbers, int count);
void	push_stack(t_stack *stack, int index, int data);

#endif