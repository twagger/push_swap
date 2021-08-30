/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 08:41:39 by twagner           #+#    #+#             */
/*   Updated: 2021/08/16 08:21:49 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_code(char *code, int is_blank)
{
	if (is_blank)
		return (NULL);
	else
		return (code);
}

int	ft_try_multiple_sorts(t_stack *a, t_stack *b)
{
	int	res;
	int	i;
	int	best_score;
	int	best_method;

	best_score = INT_MAX;
	i = -1;
	while (++i < 3)
	{
		res = ft_lazysort(a, b, i, BLANK);
		if (res == ERROR)
			return (ERROR);
		if (res < best_score)
		{
			best_score = res;
			best_method = i;
		}
		a->nb_ope = 0;
		b->nb_ope = 0;
	}
	res = ft_lazysort(a, b, best_method, REAL);
	if (res == ERROR)
		return (ERROR);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ft_parser(ac, av, &a, &b) == ERROR)
		return (ft_cleaner(a, b, "Error", 1));
	if (ft_simplify_stack(a) == ERROR)
		return (ft_cleaner(a, b, "Error", 1));
	if (a->top != -1)
	{
		if (ft_try_multiple_sorts(a, b) == ERROR)
			return (ft_cleaner(a, b, "Error", 1));
	}
	return (ft_cleaner(a, b, NULL, 0));
}
