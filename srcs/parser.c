/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 09:05:04 by twagner           #+#    #+#             */
/*   Updated: 2021/08/14 08:40:52 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_items(char *str)
{
	int	result;

	result = 0;
	if (ft_strchr(str, ' '))
	{
		while (*str)
		{
			while (*str == ' ')
				++str;
			if (*str)
			{
				++result;
				while (*str && *str != ' ')
					++str;
			}
		}
	}
	else if (*str)
		return (1);
	return (result);
}

int	ft_parser(int ac, char **av, t_stack **a, t_stack **b)
{
	int				i;
	unsigned int	size;

	size = 0;
	i = 0;
	while (++i < ac)
		size += ft_count_items(av[i]);
	*a = ft_create_stack(size, 0);
	*b = ft_create_stack(size, 1);
	if (!*a || !*b)
		return (ERROR);
	i = 0;
	while (++i < ac)
	{
		if (ft_fill_stack(*a, av[i]) == ERROR)
			return (ERROR);
	}
	ft_reverse_stack(*a);
	return (0);
}
