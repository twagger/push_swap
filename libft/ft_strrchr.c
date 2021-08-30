/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 08:00:52 by twagner           #+#    #+#             */
/*   Updated: 2021/05/21 08:09:18 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i))
		++i;
	while (i >= 0)
	{	
		if (*(s + i) == (char)c)
			return (((char *)s + i));
		--i;
	}
	return (NULL);
}
