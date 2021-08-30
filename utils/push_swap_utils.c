/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 10:00:19 by twagner           #+#    #+#             */
/*   Updated: 2021/08/15 15:26:40 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(char *code, t_stack *stack1, t_stack *stack2)
{
	int	swap;

	if (stack1->top >= 1)
	{
		swap = stack1->array[stack1->top];
		stack1->array[stack1->top] = stack1->array[stack1->top - 1];
		stack1->array[stack1->top - 1] = swap;
		++(stack1->nb_ope);
	}
	if (stack2 && stack2->top >= 1)
	{
		swap = stack2->array[stack2->top];
		stack2->array[stack2->top] = stack2->array[stack2->top - 1];
		stack2->array[stack2->top - 1] = swap;
	}
	if (code)
	{
		ft_putstr_fd((char *)code, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	ft_push(char *code, t_stack *dest, t_stack *src)
{
	int	item;

	if (!is_empty(src))
	{
		item = pop(src);
		push(dest, item);
		++(src->nb_ope);
	}
	if (code)
	{
		ft_putstr_fd((char *)code, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	ft_rotate(char *code, t_stack *stack1, t_stack *stack2)
{
	int	i;
	int	top;

	if (!is_empty(stack1))
	{
		i = stack1->top + 1;
		top = peek(stack1);
		while (--i > 0)
			stack1->array[i] = stack1->array[i - 1];
		stack1->array[0] = top;
		++(stack1->nb_ope);
	}
	if (stack2 && !is_empty(stack2))
	{
		i = stack2->top + 1;
		top = peek(stack2);
		while (--i > 0)
			stack2->array[i] = stack2->array[i - 1];
		stack2->array[0] = top;
	}
	if (code)
	{
		ft_putstr_fd((char *)code, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	ft_rev_rotate(char *code, t_stack *stack1, t_stack *stack2)
{
	int	i;
	int	bottom;

	if (!is_empty(stack1))
	{
		i = 0;
		bottom = stack1->array[0];
		while (++i <= stack1->top)
			stack1->array[i - 1] = stack1->array[i];
		stack1->array[stack1->top] = bottom;
		++(stack1->nb_ope);
	}
	if (stack2 && !is_empty(stack2))
	{
		i = 0;
		bottom = stack2->array[0];
		while (++i <= stack2->top)
			stack2->array[i - 1] = stack2->array[i];
		stack2->array[stack2->top] = bottom;
	}
	if (code)
	{
		ft_putstr_fd((char *)code, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	ft_rot_or_rev_rot(t_stack *a, t_stack *b, int nb_rot, int direction)
{
	while (nb_rot > 0)
	{
		if (direction == REV_ROT)
		{
			if (a && b)
				ft_rev_rotate("rrr", a, b);
			else if (a)
				ft_rev_rotate("rra", a, NULL);
			else if (b)
				ft_rev_rotate("rrb", b, NULL);
		}
		else if (direction == ROT)
		{
			if (a && b)
				ft_rotate("rr", a, b);
			else if (a)
				ft_rotate("ra", a, NULL);
			else if (b)
				ft_rotate("rb", b, NULL);
		}
		--nb_rot;
	}
}
