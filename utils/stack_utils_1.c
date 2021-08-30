/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:52:59 by twagner           #+#    #+#             */
/*   Updated: 2021/08/15 12:13:51 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_stack(unsigned int capacity, int num)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->capacity = capacity;
	stack->num = num;
	stack->nb_ope = 0;
	stack->top = -1;
	stack->array = (int *)malloc(sizeof(int) * capacity);
	if (!stack->array)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}

void	ft_free_stack(t_stack *stack)
{
	if (stack && stack->array)
		free(stack->array);
	if (stack)
		free(stack);
}

void	ft_reverse_stack(t_stack *stack)
{
	int	i;
	int	swap;

	if (!is_empty(stack))
	{
		i = stack->top + 1;
		while (--i > stack->top / 2)
		{
			swap = stack->array[i];
			stack->array[i] = stack->array[stack->top - i];
			stack->array[stack->top - i] = swap;
		}
	}
}

int	ft_cleaner(t_stack *a, t_stack *b, char *message, int code)
{
	if (a)
		ft_free_stack(a);
	if (b)
		ft_free_stack(b);
	if (message)
	{
		ft_putstr_fd(message, 2);
		ft_putchar_fd('\n', 2);
	}
	return (code);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->top)
	{
		if (stack->array[i] < stack->array[i + 1])
			return (0);
	}
	return (1);
}
