/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:07:26 by twagner           #+#    #+#             */
/*   Updated: 2021/08/01 10:09:36 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

int	is_full(t_stack *stack)
{
	return (stack->top == stack->capacity - 1);
}

void	push(t_stack *stack, int item)
{
	if (is_full(stack))
		return ;
	stack->array[++stack->top] = item;
}

int	pop(t_stack *stack)
{
	if (is_empty(stack))
		return (INT_MIN);
	return (stack->array[stack->top--]);
}

int	peek(t_stack *stack)
{
	if (is_empty(stack))
		return (INT_MIN);
	return (stack->array[stack->top]);
}
