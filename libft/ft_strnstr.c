/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:30:53 by miguelgo          #+#    #+#             */
/*   Updated: 2024/03/14 18:38:05 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		k = 0;
		while (needle[k] == haystack[i + k] && (i + k) < len)
		{
			if (needle[k + 1] == '\0')
				return ((char *)haystack + i);
			k++;
		}
		i++;
	}
	return (0);
}
