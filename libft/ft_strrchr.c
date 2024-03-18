/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:01:42 by miguelgo          #+#    #+#             */
/*   Updated: 2024/03/15 18:24:22 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	k;
	int	l;

	i = 0;
	l = 0;
	k = 0;
	while ((s[i] != '\0') || (i == 0))
	{
		if (s[i] == (unsigned char)c)
		{
			l = i;
			k = 1;
		}
		i++;
	}
	if (k == 1)
		return ((char *)&s[l]);
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}
