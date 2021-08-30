/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lazysort_scoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:59:22 by twagner           #+#    #+#             */
/*   Updated: 2021/08/14 15:50:03 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_score_greater_sticked(int index, t_stack *a, t_board *board)
{
	int	i;
	int	previous;
	int	score;

	score = 1;
	previous = a->array[index];
	i = index;
	if (--i < 0)
		i = a->top;
	while (i != index)
	{
		if (a->array[i] > previous && board->flags[a->array[i]] != PUSHED)
		{
			++score;
			previous = a->array[i];
			if (--i < 0)
				i = a->top;
		}
		else
			break ;
	}
	return (score);
}

int	ft_get_score_greater(int index, t_stack *a, t_board *board)
{
	int	i;
	int	previous;
	int	score;

	score = 1;
	previous = a->array[index];
	i = index;
	if (--i < 0)
		i = a->top;
	while (i != index)
	{
		if (a->array[i] > previous && board->flags[a->array[i]] != PUSHED)
		{
			++score;
			previous = a->array[i];
		}
		if (--i < 0)
			i = a->top;
	}
	return (score);
}

int	ft_get_score_next(int index, t_stack *a, t_board *board)
{
	int	i;
	int	previous;
	int	score;

	score = 1;
	previous = a->array[index];
	i = index;
	if (--i < 0)
		i = a->top;
	while (i != index)
	{
		if (a->array[i] == previous + 1 && board->flags[a->array[i]] != PUSHED)
		{
			++score;
			previous = a->array[i];
		}
		if (--i < 0)
			i = a->top;
	}
	return (score);
}

int	ft_get_score(int index, t_stack *a, t_board *board, int method)
{
	int	score;

	if (method == IS_GREATER)
		score = ft_get_score_greater(index, a, board);
	if (method == IS_GREATER_STICKED)
		score = ft_get_score_greater_sticked(index, a, board);
	else if (method == IS_NEXT)
		score = ft_get_score_next(index, a, board);
	return (score);
}
