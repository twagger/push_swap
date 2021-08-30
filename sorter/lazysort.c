/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lazysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 08:10:29 by twagner           #+#    #+#             */
/*   Updated: 2021/08/15 22:01:46 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Lazy because it don't sort A, it just try to benefit from it initial sort
*/

int	ft_is_swap_good(t_board board, t_stack *a, int method)
{
	int	res;
	int	before_max;

	res = 0;
	before_max = board.nb_ordered;
	ft_swap(NULL, a, NULL);
	if (ft_fill_board(&board, a, method, BLANK) > before_max)
		res = 1;
	ft_swap(NULL, a, NULL);
	return (res);
}

void	ft_push_to_b(t_stack *a, t_stack *b, t_board *board, int method)
{
	while (ft_has_pushable(board))
	{
		if (ft_is_swap_good(*board, a, method))
		{
			ft_swap(ft_code("sa", board->is_blank), a, NULL);
			ft_fill_board(board, a, method, REAL);
		}
		else if (board->flags[a->array[a->top]] == TO_PUSH)
		{
			board->flags[a->array[a->top]] = PUSHED;
			ft_push(ft_code("pb", board->is_blank), b, a);
		}
		else
			ft_rotate(ft_code("ra", board->is_blank), a, NULL);
	}
}

int	ft_best_index_to_push(t_stack *a, t_stack *b, int is_blank)
{
	int	i;
	int	best;
	int	count;
	int	best_count;

	i = -1;
	best_count = INT_MAX;
	best = b->top;
	while (++i < b->top + 1)
	{
		count = 0;
		count += ft_put_top_b(i, b, BLANK, is_blank);
		if (count < 0)
			count *= -1;
		if (ft_rot_a_before(a, b->array[i], BLANK, is_blank) < 0)
			count += (ft_rot_a_before(a, b->array[i], BLANK, is_blank) * -1);
		else
			count += ft_rot_a_before(a, b->array[i], BLANK, is_blank);
		if (count < best_count)
		{
			best_count = count;
			best = i;
		}
	}
	return (best);
}

void	ft_push_back_to_a(t_stack *a, t_stack *b, int is_blank)
{
	int	best;
	int	rot_a;
	int	rot_b;

	while (!is_empty(b))
	{
		best = ft_best_index_to_push(a, b, is_blank);
		rot_b = ft_put_top_b(best, b, BLANK, is_blank);
		rot_a = ft_rot_a_before(a, b->array[best], BLANK, is_blank);
		if (rot_a * rot_b > 0 && !is_blank)
			ft_efficient_rotate(a, b, rot_a, rot_b);
		else
		{
			ft_put_top_b(best, b, REAL, is_blank);
			ft_rot_a_before(a, b->array[b->top], REAL, is_blank);
		}
		ft_push(ft_code("pa", is_blank), a, b);
	}
}

int	ft_lazysort(t_stack *a, t_stack *b, int method, int is_blank)
{
	t_board	*board;
	int		nb_ope;

	if (is_blank)
	{
		if (ft_dup_stacks(&a, &b) == ERROR)
			return (ERROR);
	}
	board = ft_create_board(a->capacity, is_blank);
	if (!board && is_blank)
		return (ft_cleaner(a, b, "Error", ERROR));
	else if (!board)
		return (ERROR);
	ft_fill_board(board, a, method, REAL);
	ft_push_to_b(a, b, board, method);
	ft_push_back_to_a(a, b, is_blank);
	ft_put_top_a(ft_get_index(0, a->array, a->capacity), a, REAL, is_blank);
	nb_ope = a->nb_ope + b->nb_ope;
	if (is_blank)
		ft_cleaner(a, b, NULL, 0);
	free(board->flags);
	free(board);
	return (nb_ope);
}
