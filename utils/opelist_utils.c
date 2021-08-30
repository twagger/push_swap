/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opelist_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 12:06:06 by twagner           #+#    #+#             */
/*   Updated: 2021/08/16 08:47:08 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ope	*ft_openew(int code)
{
	t_ope	*new;

	if (code == ERROR)
		return (NULL);
	new = (t_ope *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->code = code;
	new->next = NULL;
	return (new);
}

t_ope	*ft_opelast(t_ope *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

int	ft_opeadd_back(t_ope **lst, t_ope *new)
{
	if (!new)
		return (ERROR);
	if (*lst)
		ft_opelast(*lst)->next = new;
	else
		*lst = new;
	return (0);
}

void	ft_opedelone(t_ope *comm)
{
	if (comm)
		free(comm);
}

void	ft_opeclear(t_ope **lst)
{
	t_ope	*next;

	while (*lst)
	{
		next = (*lst)->next;
		ft_opedelone(*lst);
		*lst = next;
	}
	lst = NULL;
}
