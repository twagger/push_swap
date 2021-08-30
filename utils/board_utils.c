/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 10:21:03 by twagner           #+#    #+#             */
/*   Updated: 2021/08/15 11:41:12 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_board	*ft_create_board(unsigned int capacity, int is_blank)
{
	t_board	*board;

	board = (t_board *)malloc(sizeof(*board));
	if (!board)
		return (NULL);
	board->flags = (int *)malloc(sizeof(int) * capacity);
	if (!board->flags)
	{
		free(board);
		return (NULL);
	}
	board->is_blank = 0;
	if (is_blank)
		board->is_blank = 1;
	board->size = capacity;
	board->best_top = -1;
	board->nb_ordered = 0;
	return (board);
}

int	ft_get_condition(t_stack *a, int method, int index, int previous)
{
	int	result;

	result = a->array[index] > previous;
	if (method == IS_GREATER_STICKED)
		result = a->array[index] > previous \
		&& ft_get_index(previous, a->array, a->top + 1) == index - 1;
	else if (method == IS_NEXT)
		result = a->array[index] == previous + 1;
	return (result);
}

void	ft_set_flags(t_board *board, t_stack *a, int method)
{
	int	i;
	int	previous;
	int	condition;

	previous = a->array[board->best_top];
	i = board->best_top;
	if (--i < 0)
		i = a->top;
	while (i != board->best_top)
	{
		condition = ft_get_condition(a, method, i, previous);
		if (condition && board->flags[a->array[i]] != PUSHED)
		{
			board->flags[a->array[i]] = TO_KEEP;
			previous = a->array[i];
		}
		else
			board->flags[a->array[i]] = TO_PUSH;
		if (--i < 0)
			i = a->top;
	}
	board->flags[a->array[i]] = 1;
}

int	ft_fill_board(t_board *board, t_stack *a, int method, int blank)
{
	int	i;
	int	max_score;
	int	cur_score;

	max_score = 0;
	i = a->top + 1;
	while (--i >= 0)
	{
		cur_score = ft_get_score(i, a, board, method);
		if (cur_score > max_score)
		{
			max_score = cur_score;
			board->best_top = i;
			board->nb_ordered = max_score;
		}
	}
	if (blank)
		return (max_score);
	ft_set_flags(board, a, method);
	return (-1);
}

int	ft_has_pushable(t_board	*board)
{
	int	i;

	i = -1;
	while (++i < board->size)
	{
		if (board->flags[i] == TO_PUSH)
			return (1);
	}
	return (0);
}
