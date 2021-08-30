/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:25:31 by twagner           #+#    #+#             */
/*   Updated: 2021/08/15 23:19:01 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_sorted_from_stack(t_stack *a, int **sorted)
{
	int	i;
	int	swap;

	i = -1;
	while (++i < a->capacity)
		(*sorted)[i] = a->array[i];
	i = -1;
	while (++i < a->capacity - 1)
	{
		if ((*sorted)[i] > (*sorted)[i + 1])
		{
			swap = (*sorted)[i];
			(*sorted)[i] = (*sorted)[i + 1];
			(*sorted)[i + 1] = swap;
			i = -1;
		}
	}
}

int	ft_simplify_stack(t_stack *stack)
{
	int	i;
	int	size;
	int	*sorted;

	sorted = (int *)malloc(sizeof(*sorted) * stack->capacity);
	if (!sorted)
		return (ERROR);
	ft_get_sorted_from_stack(stack, &sorted);
	i = -1;
	size = stack->capacity;
	while (++i < size)
		stack->array[i] = ft_get_index(stack->array[i], sorted, size);
	i = -1;
	free(sorted);
	return (0);
}

int	*ft_dup_array(int *arr, int size, int copy)
{
	int	i;
	int	*new;

	new = (int *)malloc(sizeof(*new) * size);
	if (!new)
		return (NULL);
	i = -1;
	if (copy)
	{	
		while (++i < size)
			new[i] = arr[i];
	}
	return (new);
}

int	ft_dup_stacks(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*old_a;

	old_a = *a;
	*a = ft_create_stack(old_a->capacity, 0);
	if (!*a)
		return (ERROR);
	*b = ft_create_stack(old_a->capacity, 1);
	if (!*b)
		return (ft_cleaner(*a, NULL, NULL, ERROR));
	(*a)->top = old_a->top;
	i = -1;
	while (++i < old_a->capacity)
		(*a)->array[i] = old_a->array[i];
	return (0);
}
