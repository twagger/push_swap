/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:08:44 by twagner           #+#    #+#             */
/*   Updated: 2021/08/15 21:17:35 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_put_top_a(int index, t_stack *a, int blank, int is_blank)
{
	int	middle;
	int	nb_rot;

	if (index == a->top)
		return (0);
	middle = (a->top + 1) / 2;
	nb_rot = a->top - index;
	if (index < middle)
		nb_rot = index + 1;
	if (blank && index < middle)
		return (nb_rot * -1);
	if (blank)
		return (nb_rot);
	while (nb_rot--)
	{
		if (index < middle)
			ft_rev_rotate(ft_code("rra", is_blank), a, NULL);
		else
			ft_rotate(ft_code("ra", is_blank), a, NULL);
	}
	return (0);
}

int	ft_put_top_b(int index, t_stack *b, int blank, int is_blank)
{
	int	middle;
	int	nb_rot;

	if (index == b->top)
		return (0);
	middle = (b->top + 1) / 2;
	nb_rot = b->top - index;
	if (index < middle)
		nb_rot = index + 1;
	if (blank && index < middle)
		return (nb_rot * -1);
	if (blank)
		return (nb_rot);
	while (nb_rot--)
	{
		if (index < middle)
			ft_rev_rotate(ft_code("rrb", is_blank), b, NULL);
		else
			ft_rotate(ft_code("rb", is_blank), b, NULL);
	}
	return (0);
}

int	ft_get_index(int value, int *array, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (array[i] == value)
			return (i);
	}
	return (ERROR);
}

int	ft_rot_a_before(t_stack *a, int value, int blank, int is_blank)
{
	int	i;
	int	i_top;
	int	min;
	int	max;
	int	closer;

	i = -1;
	min = INT_MAX;
	max = -1;
	closer = INT_MAX;
	while (++i <= a->top)
	{
		if (a->array[i] > max)
			max = a->array[i];
		if (a->array[i] < min)
			min = a->array[i];
		if (a->array[i] > value && a->array[i] < closer)
			closer = a->array[i];
	}
	if (value < min || value > max)
		i_top = ft_get_index(min, a->array, a->top + 1);
	else
		i_top = ft_get_index(closer, a->array, a->top + 1);
	return (ft_put_top_a(i_top, a, blank, is_blank));
}

void	ft_efficient_rotate(t_stack *a, t_stack *b, int rot_a, int rot_b)
{
	int	rot_r;
	int	direction;

	direction = ROT;
	if (rot_a < 0)
	{
		direction = REV_ROT;
		rot_a *= -1;
		rot_b *= -1;
	}
	if (rot_a > rot_b)
	{
		rot_r = rot_b;
		rot_a -= rot_b;
		rot_b = 0;
	}
	else
	{
		rot_r = rot_a;
		rot_b -= rot_a;
		rot_a = 0;
	}
	ft_rot_or_rev_rot(a, b, rot_r, direction);
	ft_rot_or_rev_rot(a, NULL, rot_a, direction);
	ft_rot_or_rev_rot(NULL, b, rot_b, direction);
}
