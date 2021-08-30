/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 08:41:30 by twagner           #+#    #+#             */
/*   Updated: 2021/08/16 09:58:00 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>
# include <limits.h>
# define ERROR -1
# define TOP 1
# define BOTTOM 2
# define OPERATIONS "absababrabr"
# define PUSHED -1
# define TO_PUSH 0
# define TO_KEEP 1
# define REAL 0
# define BLANK 1
# define IS_GREATER 0
# define IS_GREATER_STICKED 1
# define IS_NEXT 2
# define ROT 1
# define REV_ROT 0

typedef struct s_stack
{
	int	top;
	int	*array;
	int	capacity;
	int	num;
	int	nb_ope;
}		t_stack;

typedef struct s_ope
{
	int				code;
	struct s_ope	*next;
}					t_ope;

typedef struct s_board
{
	int	*flags;
	int	size;
	int	best_top;
	int	nb_ordered;
	int	is_blank;
}		t_board;

int		ft_parser(int ac, char **av, t_stack **a, t_stack **b);
t_stack	*ft_create_stack(unsigned int capacity, int num);
void	ft_free_stack(t_stack *stack);
int		ft_fill_stack(t_stack *stack, char *str);
void	ft_reverse_stack(t_stack *stack);
int		is_empty(t_stack *stack);
int		is_sorted(t_stack *stack);
int		is_full(t_stack *stack);
void	push(t_stack *stack, int item);
int		pop(t_stack *stack);
int		peek(t_stack *stack);
int		ft_cleaner(t_stack *a, t_stack *b, char *message, int code);
int		ft_simplify_stack(t_stack *stack);
void	ft_get_sorted_from_stack(t_stack *a, int **sorted);

t_ope	*ft_opelast(t_ope *lst);
int		ft_opeadd_back(t_ope **lst, t_ope *new);
void	ft_opedelone(t_ope *comm);
void	ft_opeclear(t_ope **lst);
t_ope	*ft_openew(int code);
int		ft_ope_cleaner(t_ope **opelist, char *line, int ret);

void	ft_swap(char *code, t_stack *stack1, t_stack *stack2);
void	ft_push(char *code, t_stack *dest, t_stack *src);
void	ft_rotate(char *code, t_stack *stack1, t_stack *stack2);
void	ft_rev_rotate(char *code, t_stack *stack1, t_stack *stack2);
void	ft_rot_or_rev_rot(t_stack *a, t_stack *b, int nb_rot, int direction);

int		ft_lazysort(t_stack *a, t_stack *b, int method, int is_blank);
int		ft_get_index(int value, int *array, int size);
int		ft_rot_a_before(t_stack *a, int value, int blank, int is_blank);
void	ft_efficient_rotate(t_stack *a, t_stack *b, int rot_a, int rot_b);
int		ft_put_top_a(int index, t_stack *a, int blank, int is_blank);
int		ft_put_top_b(int index, t_stack *b, int blank, int is_blank);

t_board	*ft_create_board(unsigned int capacity, int is_blank);
int		ft_fill_board(t_board *board, t_stack *a, int method, int blank);
int		ft_get_score(int index, t_stack *a, t_board *board, int method);
void	ft_set_flags(t_board *board, t_stack *a, int method);
int		ft_has_pushable(t_board	*board);

char	*ft_code(char *code, int is_blank);
int		ft_dup_stacks(t_stack **a, t_stack **b);

#endif