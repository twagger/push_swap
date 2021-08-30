/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 09:55:43 by twagner           #+#    #+#             */
/*   Updated: 2021/08/16 10:12:22 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ope_cleaner(t_ope **opelist, char *line, int ret)
{
	if (line)
		free(line);
	if (opelist)
		ft_opeclear(opelist);
	return (ret);
}
