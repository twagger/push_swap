/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:36:15 by twagner           #+#    #+#             */
/*   Updated: 2021/08/14 16:57:25 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_param_valid(char *str)
{
	char	previous;

	previous = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			if (*str != '-' && *str != '+' && *str != ' ')
				return (0);
			if ((*str == '-' || *str == '+') \
				&& (previous != 0 && previous != ' '))
				return (0);
			previous = *str;
		}
		++str;
	}
	return (1);
}

static int	ft_is_item_int(char *str)
{
	int		sign;
	double	nb;
	int		has_digit;

	nb = 0;
	sign = 1;
	has_digit = 0;
	if (!*str)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	if (*str == '+' || *str == '-')
	{
		sign = sign + (43 - *str);
		++str;
	}
	while (ft_isdigit(*str))
	{
		has_digit = 1;
		nb = (nb * 10) + (*str - 48);
		++str;
	}
	if (nb * sign > INT_MAX || nb * sign < INT_MIN)
		return (0);
	return (has_digit);
}

static int	ft_is_item_in_stack(int item, t_stack *stack)
{
	int	i;

	i = -1;
	while (++i <= stack->top)
	{
		if (item == stack->array[i])
			return (1);
	}
	return (0);
}

static int	ft_convert_and_push(t_stack *stack, char *str)
{
	int	item;

	if (!ft_is_item_int(str))
		return (ERROR);
	item = ft_atoi(str);
	if (ft_is_item_in_stack(item, stack))
		return (ERROR);
	push(stack, item);
	return (0);
}

int	ft_fill_stack(t_stack *stack, char *str)
{
	if (!ft_is_param_valid(str))
		return (ERROR);
	if (ft_strchr(str, ' '))
	{
		while (*str)
		{
			while (*str == ' ')
				++str;
			if (*str)
			{
				if (ft_convert_and_push(stack, str) == ERROR)
					return (ERROR);
				str = ft_strchr(str, ' ');
				if (!str)
					break ;
			}
		}
	}
	else if (*str)
	{
		if (ft_convert_and_push(stack, str) == ERROR)
			return (ERROR);
	}
	return (0);
}
